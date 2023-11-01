#pragma once
#include <memory>
#include "IHistoryDocumentCommand.h"
#include "CDocumentItem.h"
#include "IDocument.h"
class CSetTitleCommand :
    public IHistoryDocumentCommand
{
public:

	CSetTitleCommand(std::string newTitle, std::string prevTitle, IDocument* document)
		: m_newTitle(newTitle)
		, m_prevTitle(prevTitle)
		, m_document(document)
	{
	}

	void Execute() override
	{
		m_document->SetTitleWithoutAddingToHisotry(m_newTitle);
	}

	void Unexecute() override
	{
		m_document->SetTitleWithoutAddingToHisotry(m_prevTitle);
	}

	void Destroy() override
	{
	}

private:
	std::string m_newTitle;
	std::string m_prevTitle;
	IDocument* m_document;

};

