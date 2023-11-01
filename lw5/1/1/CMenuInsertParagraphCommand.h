#pragma once
#include <algorithm>
#include "IMenuCommand.h"
#include "IDocument.h"
class CMenuInsertParagraphCommand :
    public IMenuCommand
{
public:
    CMenuInsertParagraphCommand(IDocument& document)
        :m_document(document)
    {
    }

    void Execute(const std::string& parametrs) override
    {
        std::string insertParagraphParametrs(parametrs.begin() + parametrs.find_first_of(' ')+1, parametrs.end());
        /*std::copy(
            parametrs.begin() + parametrs.find_first_of(' '), 
            parametrs.end(), 
            insertParagraphParametrs.begin()
        );*/

        if (insertParagraphParametrs.begin() + insertParagraphParametrs.find_first_of(' ') == insertParagraphParametrs.end())
        {
            throw std::invalid_argument("invalid arguments count");
        }

        std::string stringPosition(insertParagraphParametrs.begin(), insertParagraphParametrs.begin() + insertParagraphParametrs.find_first_of(' '));

        std::string text(insertParagraphParametrs.begin() +  insertParagraphParametrs.find_first_of(' '), insertParagraphParametrs.end());

        if (stringPosition == "end")
        {
            m_document.InsertParagraph(text);
        }
        else if (!CheckOnPositiveNumbers::CheckStringOnPositiveNumber(stringPosition))
        {
            m_document.InsertParagraph(text, std::stoll(stringPosition));
        }
        else
        {
            throw std::invalid_argument("position must be positive number or 'end'");
        }
    }

private:
    IDocument& m_document;
};

