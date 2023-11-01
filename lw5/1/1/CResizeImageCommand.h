#pragma once
#include <memory>
#include "IHistoryDocumentCommand.h"
#include "CDocumentItem.h"
#include "IDocument.h"
class CResizeImageCommand :
    public IHistoryDocumentCommand
{
	//передавать документ по умному указателю
public:
	CResizeImageCommand(size_t position, unsigned int prevWidth, unsigned int prevHeight, unsigned int newWidth, unsigned int newHeight, IDocument* document)
		: m_position(position)
		, m_prevWidth(prevWidth)
		, m_prevHeight(prevHeight)
		, m_newWidth(newWidth)
		, m_newHeight(newHeight)
		, m_document(document)
	{
	}

	void Execute() override
	{
		m_document->ResizeImageWithoutAddingToHisotry(m_position, m_newWidth, m_newHeight);
	}

	void Unexecute() override
	{
		m_document->ResizeImageWithoutAddingToHisotry(m_position, m_prevWidth, m_prevHeight);
	}

	//убрать 
	void Destroy() override
	{
	}

private:
	size_t m_position;
	unsigned int m_prevWidth;
	unsigned int m_prevHeight;
	unsigned int m_newWidth;
	unsigned int m_newHeight;
	IDocument* m_document;

};

