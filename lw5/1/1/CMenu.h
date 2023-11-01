#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <algorithm>
#include "IMenuCommand.h"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
class CMenu
{
public:
    void AddItem(const std::string& shortcut,const std::string& description,
        std::unique_ptr<IMenuCommand>&& command)
    {
        m_items.emplace_back(shortcut, description, std::move(command));
    }

    void Run()
    {
        std::string command;
        while ((std::cout << ">")
            && std::getline(std::cin, command)
            && ExecuteCommand(command))
        {
        }
    }

    void ShowInstructions()const
    {
        std::cout << "Commands list:\n";
        for (auto& item : m_items)
        {
            std::cout << "  " << item.m_shortcut << ": " << item.m_description << "\n";
        }
    }

    void Exit()
    {
        m_exit = true;
    }
private:
    struct Item
    {
        Item(const std::string& shortcut, const std::string& description,
            std::unique_ptr<IMenuCommand>&& command)
            : m_shortcut(shortcut)
            , m_description(description)
            , m_command(std::move(command))
        {}

        std::string m_shortcut;
        std::string m_description;
        std::unique_ptr<IMenuCommand> m_command;
    };

    bool ExecuteCommand(const std::string& command)
    {
        m_exit = false;

        std::vector<std::string> parametrsVector;
        boost::split(parametrsVector, command, boost::is_any_of(" "), boost::token_compress_on);

        auto it = std::find_if(m_items.begin(), m_items.end(), [&](const Item& item) {
            return item.m_shortcut == parametrsVector[0];
            });

        try
        {
            if (it != m_items.end())
                it->m_command->Execute(command);
            else
                std::cout << "Unknown command\n";
        }
        catch (std::exception& ex)
        {
            std::cout << ex.what() << "\n";
        }
        return !m_exit;
    }

    std::vector<Item> m_items;
    bool m_exit = false;
};

