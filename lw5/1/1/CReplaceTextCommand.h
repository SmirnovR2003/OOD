#pragma once
#include <memory>
#include "IHistoryDocumentCommand.h"
#include "CDocumentItem.h"
#include "IDocument.h"
class CReplaceTextCommand :
    public IHistoryDocumentCommand
{
public:
	CReplaceTextCommand(size_t position, std::string newText, std::string prevText, IDocument* document)
		: m_position(position)
		, m_newText(newText)
		, m_prevText(prevText)
		, m_document(document)
	{
	}

	void Execute() override
	{
		m_document->ReplaceTextWithoutAddingToHisotry(m_position, m_newText);
	}

	void Unexecute() override
	{
		m_document->ReplaceTextWithoutAddingToHisotry(m_position, m_prevText);
	}

	void Destroy() override
	{
	}

private:
	size_t m_position;
	std::string m_newText;
	std::string m_prevText;
	IDocument* m_document;
};

