#pragma once
#include "IMenuCommand.h"
#include "IDocument.h"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
class CMenuInsertImageCommand :
    public IMenuCommand
{
public:
    CMenuInsertImageCommand(IDocument& document)
        :m_document(document)
    {
    }

    void Execute(const std::string& parametrs) override
    {
        std::vector<std::string> parametrsVector;
        boost::split(parametrsVector, parametrs, boost::is_any_of(" "), boost::token_compress_on);

        if (parametrsVector.size() != 5)
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

        if (parametrsVector[1] == "end")
        {
            m_document.InsertImage(parametrsVector[4], std::stol(parametrsVector[2]), std::stol(parametrsVector[3]));
        }
        else if (!CheckOnPositiveNumbers::CheckStringOnPositiveNumber(parametrsVector[1]))
        {
            m_document.InsertImage(parametrsVector[4], std::stol( parametrsVector[2]), std::stol(parametrsVector[3]),std::stoll(parametrsVector[1]));
        }
        else
        {
            throw std::invalid_argument("position must be positive number or 'end'");
        }
    }

private:
    IDocument& m_document;
};

