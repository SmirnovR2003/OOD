#pragma once
#include "IMenuCommand.h"
#include "CMenu.h"
class CExitMenuCommand :
    public IMenuCommand
{
public:
    CExitMenuCommand(CMenu& menu)
        :m_menu(menu)
    {}

    void Execute(const std::string& parametrs) override
    {
        m_menu.Exit();
    }
private:
    CMenu& m_menu;
};

