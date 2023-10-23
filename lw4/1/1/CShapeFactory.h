#pragma once
#include "IShapeFactory.h"
#include "CEllipse.h"
#include "CRectangle.h"
#include "CRegularPolygon.h"
#include "CTriangle.h"
#include <vector>
#include <algorithm>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <functional>
#include <map>
#include <memory>


std::shared_ptr<CShape> CreateEllipse(const std::vector<std::string>& descr);
std::shared_ptr<CShape> CreateRectangle(const std::vector<std::string>& descr);
std::shared_ptr<CShape> CreateTriangle(const std::vector<std::string>& descr);
std::shared_ptr<CShape> CreateRegularPolygon(const std::vector<std::string>& descr);

const std::map<std::string, std::function<std::shared_ptr<CShape>(const std::vector<std::string>& descr)>> CREATE_SHAPES_FUNCTIONS
{
    {"ellipse", CreateEllipse},
    {"rectangle", CreateRectangle},
    {"triangle", CreateTriangle},
    {"regularpolygon", CreateRegularPolygon},
};

const std::map<std::string, sf::Color> COLORS
{
    {"green", sf::Color::Green},
    {"red", sf::Color::Red},
    {"blue", sf::Color::Blue},
    {"yellow", sf::Color::Yellow},
    {"pink", sf::Color(255,77,225)},
    {"black", sf::Color::Black}
};

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

class CShapeFactory :
    public IShapeFactory
{
public:
    std::shared_ptr<CShape> CreateShape(const std::string& descr)
    {
        std::vector<std::string> splitedDescr;
        boost::split(splitedDescr, descr, boost::is_any_of(" "), boost::token_compress_on);

        std::transform(splitedDescr[0].begin(), splitedDescr[0].end(), splitedDescr[0].begin(), [](char ch) {return tolower(ch);});

        return CREATE_SHAPES_FUNCTIONS.find(splitedDescr[0])->second(splitedDescr);
    }

};

std::shared_ptr<CShape> CreateEllipse(const std::vector<std::string>& descr)
{
    if (descr.size() != 6)
    {
        throw std::invalid_argument("invalid number of ellipse arguments");
    }

    if (COLORS.count(descr[1]) == 0)
    {
        throw std::invalid_argument("invalid ellipse color");
    }
    auto color = COLORS.find(descr[1])->second;

    if (!CheckVectorOnPositiveNumbers({ descr[2] ,descr[3] ,descr[4] ,descr[5] }))
    {
        throw std::invalid_argument("invalid ellipse arguments");
    }

    CEllipse ellipse(color, {std::stod(descr[2]) ,std::stod(descr[3])}, std::stod(descr[4]), std::stod(descr[5]));

    return std::make_unique<CEllipse>(ellipse);
}

std::shared_ptr<CShape> CreateRectangle(const std::vector<std::string>& descr)
{
    if (descr.size() != 6)
    {
        throw std::invalid_argument("invalid number of rectangle arguments");
    }

    if (COLORS.count(descr[1]) == 0)
    {
        throw std::invalid_argument("invalid rectangle color");
    }
    auto color = COLORS.find(descr[1])->second;

    if (!CheckVectorOnPositiveNumbers({ descr[2] ,descr[3] ,descr[4] ,descr[5] }))
    {
        throw std::invalid_argument("invalid rectangle arguments");
    }

    CRectangle rectangle(color, { std::stod(descr[2]) ,std::stod(descr[3]) }, { std::stod(descr[4]), std::stod(descr[5]) });

    return std::make_unique<CRectangle>(rectangle);

}

std::shared_ptr<CShape> CreateTriangle(const std::vector<std::string>& descr)
{
    if (descr.size() != 8)
    {
        throw std::invalid_argument("invalid number of triangle arguments");
    }

    if (COLORS.count(descr[1]) == 0)
    {
        throw std::invalid_argument("invalid triangle color");
    }
    auto color = COLORS.find(descr[1])->second;

    if (!CheckVectorOnPositiveNumbers({ descr[2], descr[3], descr[4], descr[5], descr[6], descr[7]}))
    {
        throw std::invalid_argument("invalid triangle arguments");
    }

    CTriangle triangle(
        color, 
        { std::stod(descr[2]) ,std::stod(descr[3]) }, 
        { std::stod(descr[4]), std::stod(descr[5]) },
        { std::stod(descr[6]), std::stod(descr[7]) }
    );

    return std::make_unique<CTriangle>(triangle);
}

std::shared_ptr<CShape> CreateRegularPolygon(const std::vector<std::string>& descr)
{
    if (descr.size() != 6)
    {
        throw std::invalid_argument("invalid number of regular polygon arguments");
    }

    if (COLORS.count(descr[1]) == 0)
    {
        throw std::invalid_argument("invalid regular polygon color");
    }
    auto color = COLORS.find(descr[1])->second;

    if (!CheckVectorOnPositiveNumbers({ descr[2] ,descr[3] ,descr[4] ,descr[5] }))
    {
        throw std::invalid_argument("invalid regular polygon arguments");
    }

    CRegularPolygon regularPolygon(color, { std::stod(descr[2]) ,std::stod(descr[3]) }, std::stod(descr[4]), std::stoi(descr[5]));

    return std::make_unique<CRegularPolygon>(regularPolygon);

}
