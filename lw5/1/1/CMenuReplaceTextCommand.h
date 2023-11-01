#pragma once
#include "IMenuCommand.h"
#include "IDocument.h"
class CMenuReplaceTextCommand :
    public IMenuCommand
{
public:
    CMenuReplaceTextCommand(IDocument& document)
        :m_document(document)
    {
    }

    void Execute(const std::string& parametrs) override
    {
        std::string replaceTextParametrs(parametrs.begin() + parametrs.find_first_of(' ') + 1, parametrs.end());

        if (replaceTextParametrs.begin() + replaceTextParametrs.find_first_of(' ') == replaceTextParametrs.end())
        {
            throw std::invalid_argument("invalid arguments count");
        }

        std::string stringPosition(replaceTextParametrs.begin(), replaceTextParametrs.begin() + replaceTextParametrs.find_first_of(' '));

        std::string text(replaceTextParametrs.begin() + replaceTextParametrs.find_first_of(' '), replaceTextParametrs.end());

        if (CheckOnPositiveNumbers::CheckStringOnPositiveNumber(stringPosition))
        {
            m_document.ReplaceText(std::stoll(stringPosition), text);
        }
        else
        {
            throw std::invalid_argument("position must be positive number");
        }
    }

private:
    IDocument& m_document;
};

