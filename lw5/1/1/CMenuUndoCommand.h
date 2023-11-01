#pragma once
#include "IMenuCommand.h"
#include "IDocument.h"
class CMenuUndoCommand :
    public IMenuCommand
{
public:
    CMenuUndoCommand(IDocument& document)
        :m_document(document)
    {
    }

    void Execute(const std::string& parametrs) override
    {
        m_document.Undo();
    }

private:
    IDocument& m_document;
};

