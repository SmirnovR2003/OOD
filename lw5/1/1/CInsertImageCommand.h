#pragma once
#include <memory>
#include "IHistoryDocumentCommand.h"
#include "CDocumentItem.h"
#include "IDocument.h"
class CInsertImageCommand :
	public IHistoryDocumentCommand
{
public:

	CInsertImageCommand(std::vector<std::shared_ptr<CDocumentItem>>* documentItems, std::shared_ptr<CDocumentItem> item, size_t position, IDocument* document)
		: m_documentItems(documentItems)
		, m_item(item)
		, m_position(position)
		, m_document(document)
	{
	}

	void Execute() override
	{
		m_document->InsertImageWithoutAddingToHisotry(
			m_item->GetImage()->GetPath().string(),
			m_item->GetImage()->GetWidth(),
			m_item->GetImage()->GetHeight(), 
			m_position-1
		);
	}

	void Unexecute() override
	{
		m_document->DeleteItemWithoutAddingToHisotry(m_position);
	}

	void Destroy() override
	{
	}

	~CInsertImageCommand()
	{
		if (m_item->GetType() == ItemType::Image)
		{
			for (auto& item : *m_documentItems)
			{
				if (item->GetType() == ItemType::Image && item->GetImage()->GetPath() == m_item->GetImage()->GetPath())
				{
					return;
				}
			}

			std::filesystem::remove(m_item->GetImage()->GetPath().parent_path() / m_item->GetImage()->GetPath().filename());
		}
	}

private:
	std::vector<std::shared_ptr<CDocumentItem>>* m_documentItems;
	std::shared_ptr<CDocumentItem> m_item;
	size_t m_position;
	IDocument* m_document;
};

