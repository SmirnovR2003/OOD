#pragma once
#include "IMenuCommand.h"
#include "IDocument.h"
class CMenuDeleteItemCommand :
    public IMenuCommand
{
public:
    CMenuDeleteItemCommand(IDocument& document)
        :m_document(document)
    {
    }

    void Execute(const std::string& parametrs) override
    {
        std::vector<std::string> parametrsVector;
        boost::split(parametrsVector, parametrs, boost::is_any_of(" "), boost::token_compress_on);

        if (parametrsVector.size() != 2)
        {
            throw std::invalid_argument("invalid arguments count");
        }

        if (!CheckOnPositiveNumbers::CheckStringOnPositiveNumber(parametrsVector[1]))
        {
            throw std::invalid_argument("position must be positive number");
        }

        m_document.DeleteItem(std::stoll(parametrsVector[1]));
    }

private:
    IDocument& m_document;
};

