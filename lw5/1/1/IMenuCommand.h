#pragma once
#include <vector>
#include <string>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

namespace CheckOnPositiveNumbers
{

    bool CheckStringOnPositiveNumber(const std::string& s)
    {
        return (!s.empty() && s.find_first_not_of("0123456789") == std::string::npos);
    }

    bool CheckVectorOnPositiveNumbers(const std::vector<std::string>& vec)
    {
        for (auto& s : vec)
        {
            if (!CheckStringOnPositiveNumber(s))
            {
                return false;
            }
        }
        return true;
    }
};

class IMenuCommand
{
public:
	virtual void Execute(const std::string& parametrs) = 0;
	virtual ~IMenuCommand() = default;
};

