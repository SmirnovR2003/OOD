#pragma once
#include "IMenuCommand.h"
#include "IDocument.h"
#include <iostream>
class CMenuListCommand :
    public IMenuCommand
{
public:
    CMenuListCommand(IDocument& document)
        :m_document(document)
    {
    }

    void Execute(const std::string& parametrs) override
    {
        std::cout << "Title: " << m_document.GetTitle() << "\n";
        for (size_t i = 0; i < m_document.GetItemsCount(); i++)
        {
            std::cout << i+1 << ". " << m_document.GetItem(i).GetItemInfo() << "\n";
        }
    }

private:
    IDocument& m_document;
};

