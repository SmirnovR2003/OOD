#pragma once
#include "IMenuCommand.h"
#include "CMenu.h"
class CMenuHelpCommand : public IMenuCommand
{
public:
    CMenuHelpCommand(const CMenu& menu)
        :m_menu(menu)
    {}

    void Execute(const std::string& parametrs) override
    {
        m_menu.ShowInstructions();
    }
private:
    const CMenu& m_menu;
};


