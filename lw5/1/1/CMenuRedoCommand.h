#pragma once
#include "IMenuCommand.h"
#include "IDocument.h"
class CMenuRedoCommand :
    public IMenuCommand
{
public:
    CMenuRedoCommand(IDocument& document)
        :m_document(document)
    {
    }

    void Execute(const std::string& parametrs) override
    {
        m_document.Redo();
    }

private:
    IDocument& m_document;
};

