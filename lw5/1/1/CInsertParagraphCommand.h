#pragma once
#include <memory>
#include "IHistoryDocumentCommand.h"
#include "CDocumentItem.h"
#include "IDocument.h"
class CInsertParagraphCommand :
    public IHistoryDocumentCommand
{
public:

	CInsertParagraphCommand(std::shared_ptr<CDocumentItem> item, size_t position, IDocument* document)
		: m_item(item)
		, m_position(position)
		, m_document(document)
	{
	}

	void Execute() override
	{
		m_document->InsertParagraphWithoutAddingToHisotry(m_item->GetParagraph()->GetText(), m_position-1);
	}

	void Unexecute() override
	{
		m_document->DeleteItemWithoutAddingToHisotry(m_position);
	}

	void Destroy() override
	{
	}

private:
	std::shared_ptr<CDocumentItem> m_item;
	size_t m_position;
	IDocument* m_document;
};

