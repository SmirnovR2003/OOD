#include "CDocument.h"
#include "CParagraph.h"
#include "CImage.h"
#include "CInsertParagraphCommand.h"
#include "CInsertImageCommand.h"
#include "CDeleteItemCommand.h"
#include "CSetTitleCommand.h"
#include "CReplaceTextCommand.h"
#include "CResizeImageCommand.h"
#include <fstream>
#include "CDocumentHistory.h"

using namespace std;

CDocument::CDocument()
	:m_history(std::make_unique<CDocumentHistory>())
{
}

std::shared_ptr<IParagraph> CDocument::InsertParagraph(const std::string& text, std::optional<size_t> position)
{
	if (position.has_value() && position.value() >= m_documentItems.size())
	{
		throw out_of_range("position must be less then document items count");
	}

	std::shared_ptr<IParagraph> paragraph(make_shared<CParagraph>(text));

	if (position.has_value())
	{
		m_documentItems.insert(m_documentItems.begin() + position.value(), make_shared<CDocumentItem>(paragraph));
		m_history->AddCommandToHistory(make_shared<CInsertParagraphCommand>(m_documentItems[position.value()], position.value(), this));
	}
	else
	{
		m_documentItems.push_back(make_shared<CDocumentItem>(paragraph));
		m_history->AddCommandToHistory(make_shared<CInsertParagraphCommand>(m_documentItems[m_documentItems.size() - 1], m_documentItems.size() - 1, this));
	}

	return paragraph;
}

std::shared_ptr<IImage> CDocument::InsertImage(const std::string& path, int width, int height, std::optional<size_t> position)
{
	if (position.has_value() && position.value() >= m_documentItems.size())
	{
		throw out_of_range("position must be less then document items count");
	}

	std::shared_ptr<IImage> image(make_shared<CImage>(&m_documentItems, path, width, height));

	if (position.has_value())
	{
		m_documentItems.insert(m_documentItems.begin() + position.value(), make_shared<CDocumentItem>(image));
		m_history->AddCommandToHistory(make_shared<CInsertImageCommand>(&m_documentItems, m_documentItems[position.value()], position.value(), this));
	}
	else
	{
		m_documentItems.push_back(make_shared<CDocumentItem>(image));
		m_history->AddCommandToHistory(make_shared<CInsertImageCommand>(&m_documentItems, m_documentItems[m_documentItems.size() - 1], m_documentItems.size() - 1, this));
	}

	return image;
}

size_t CDocument::GetItemsCount() const
{
	return m_documentItems.size();
}

CConstDocumentItem CDocument::GetItem(size_t index) const
{
	if (index >= m_documentItems.size())
	{
		throw out_of_range("out of range");
	}

	return *(m_documentItems[index].get());
}

CDocumentItem CDocument::GetItem(size_t index) 
{
	if (index >= m_documentItems.size())
	{
		throw out_of_range("out of range");
	}

	return *(m_documentItems[index].get());
}

void CDocument::ReplaceText(size_t position, const std::string& text)
{
	if (position >= m_documentItems.size())
	{
		throw out_of_range("out of range");
	}

	if (m_documentItems[position]->GetType() != ItemType::Paragraph)
	{
		throw logic_error("this is not paragraph");
	}

	m_history->AddCommandToHistory(make_shared<CReplaceTextCommand>(position, text, m_documentItems[position]->GetParagraph()->GetText(), this));
	m_documentItems[position]->GetParagraph()->SetText(text);
}

void CDocument::ResizeImage(size_t position, int width, int height)
{
	if (position >= m_documentItems.size())
	{
		throw out_of_range("out of range");
	}

	if (m_documentItems[position]->GetType() != ItemType::Image)
	{
		throw logic_error("this is not image");
	}

	m_history->AddCommandToHistory(make_shared<CResizeImageCommand>(
		position, 
		width, 
		height, 
		m_documentItems[position]->GetImage()->GetWidth(), 
		m_documentItems[position]->GetImage()->GetHeight(), 
		this)
	);

	m_documentItems[position]->GetImage()->Resize(width, height);
}

void CDocument::DeleteItem(size_t index)
{
	if (index >= m_documentItems.size())
	{
		throw out_of_range("out of range");
	}
	m_history->AddCommandToHistory(make_shared<CDeleteItemCommand>(&m_documentItems, m_documentItems[index], index, this));
	m_documentItems.erase(m_documentItems.begin() + index);

}

std::string CDocument::GetTitle() const
{
	return m_title;
}

void CDocument::SetTitle(const std::string& title)
{
	m_history->AddCommandToHistory(make_shared<CSetTitleCommand>(m_title, title, this));
	m_title = title;
}

bool CDocument::CanUndo() const
{
	return m_history->CanUndo();
}

void CDocument::Undo()
{
	m_history->Undo();
}

bool CDocument::CanRedo() const
{
	return m_history->CanRedo();
}

void CDocument::Redo()
{
	m_history->Redo();
}

string GetStringWithEncodeSpecificSymbols(const std::string& str)
{
	string newStr;
	for (auto ch : str)
	{
		if (ch == '<' || ch == '>' || ch == '“' || ch == '‘' || ch == '&')
		{
			newStr += '\\';
		}
		newStr += ch;
	}
	return newStr;
}

void CDocument::Save(const std::string& path) const
{
	ofstream fOut(path);
	fOut << "<!doctype html>\n"
		"<html lang = ""ru"">\n"
		"<head>\n"
		"<meta charset = ""utf-8"" />\n"
		"<title>" + GetStringWithEncodeSpecificSymbols(m_title) + "</title>\n"
		"<link rel = ""stylesheet"" href = ""style.css"" />\n"
		"</head>\n"
		"<body>\n";

	for (auto& item : m_documentItems)
	{
		if (item->GetType() == ItemType::Paragraph)
		{
			fOut << "<div>" + GetStringWithEncodeSpecificSymbols(item->GetParagraph()->GetText()) + "</div>\n";
		}
		else
		{
			fOut << "<img src=""" 
				+ GetStringWithEncodeSpecificSymbols(item->GetImage()->GetPath().string()) 
				+ """ width=" + std::to_string(item->GetImage()->GetWidth())
				+ "height=" 
				+ std::to_string(item->GetImage()->GetHeight())
				+" >\n";
		}
	}

	fOut << "</body>\n"
		"</html>\n";

	std::string directoryStr(path.begin(), path.begin() + path.find_last_of('\\'));
	std::filesystem::path directory = directoryStr + "\\images\\";

	for (auto const& file : std::filesystem::directory_iterator("images\\"))
	{
		std::filesystem::create_directories(directory);
		std::filesystem::copy_file(file, directory  / file.path().filename().string(), std::filesystem::copy_options::overwrite_existing);
	}
}

void CDocument::InsertParagraphWithoutAddingToHisotry(const std::string& text, std::optional<size_t> position)
{
	if (position.has_value() && position.value() >= m_documentItems.size())
	{
		throw out_of_range("position must be less then document items count");
	}

	std::shared_ptr<IParagraph> paragraph(make_shared<CParagraph>(text));

	if (position.has_value())
	{
		m_documentItems.insert(m_documentItems.begin() + position.value(), make_shared<CDocumentItem>(paragraph));
	}
	else
	{
		m_documentItems.push_back(make_shared<CDocumentItem>(paragraph));
	}
}

void CDocument::InsertImageWithoutAddingToHisotry(const std::string& path, int width, int height, std::optional<size_t> position)
{
	if (position.has_value() && position.value() >= m_documentItems.size())
	{
		throw out_of_range("position must be less then document items count");
	}

	std::shared_ptr<IImage> image(make_shared<CImage>(&m_documentItems, path, width, height));

	if (position.has_value())
	{
		m_documentItems.insert(m_documentItems.begin() + position.value(), make_shared<CDocumentItem>(image));
	}
	else
	{
		m_documentItems.push_back(make_shared<CDocumentItem>(image));
	}
}

void CDocument::DeleteItemWithoutAddingToHisotry(size_t index)
{
	if (index >= m_documentItems.size())
	{
		throw out_of_range("out of range");
	}
	m_documentItems.erase(m_documentItems.begin() + index);
}

void CDocument::SetTitleWithoutAddingToHisotry(const std::string& title)
{
	m_title = title;
}

void CDocument::ResizeImageWithoutAddingToHisotry(size_t position, int width, int height)
{
	if (position >= m_documentItems.size())
	{
		throw out_of_range("out of range");
	}

	if (m_documentItems[position]->GetType() != ItemType::Image)
	{
		throw logic_error("this is not image");
	}
	m_documentItems[position]->GetImage()->Resize(width, height);
}

void CDocument::ReplaceTextWithoutAddingToHisotry(size_t position, const std::string& text)
{
	if (position >= m_documentItems.size())
	{
		throw out_of_range("out of range");
	}

	if (m_documentItems[position]->GetType() != ItemType::Paragraph)
	{
		throw logic_error("this is not paragraph");
	}
	m_documentItems[position]->GetParagraph()->SetText(text);
}
 