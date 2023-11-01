#pragma once
#include "IDocument.h"
#include "IMenuCommand.h"
class CMenuResizeImageCommand :
    public IMenuCommand
{
public:
    CMenuResizeImageCommand(IDocument& document)
        :m_document(document)
    {
    }

    void Execute(const std::string& parametrs) override
    {
        std::vector<std::string> parametrsVector;
        boost::split(parametrsVector, parametrs, boost::is_any_of(" "), boost::token_compress_on);

        if (parametrsVector.size() != 4)
        {
            throw std::invalid_argument("invalid arguments count");
        }

        if (!CheckOnPositiveNumbers::CheckStringOnPositiveNumber(parametrsVector[2]))
        {
            throw std::invalid_argument("width must be positive number");
        }

        if (!CheckOnPositiveNumbers::CheckStringOnPositiveNumber(parametrsVector[3]))
        {
            throw std::invalid_argument("height must be positive number");
        }

        if (CheckOnPositiveNumbers::CheckStringOnPositiveNumber(parametrsVector[1]))
        {
            m_document.ResizeImage(std::stoll(parametrsVector[1]), std::stol(parametrsVector[2]), std::stol(parametrsVector[3]));
        }
        else
        {
            throw std::invalid_argument("position must be positive number");
        }
    }

private:
    IDocument& m_document;
};

