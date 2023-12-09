#include <iostream>
#include <string>
#include <map>
#include "CCanvas.h"
#include "CSimpleLineStyle.h"
#include "CSlide.h"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include "CTriangle.h"
#include "CEllipse.h"
#include "CRectangle.h"
#include "CGroupShape.h"

using namespace std;

shared_ptr<IShape> CreateTriangle(const string& parameters)
{
    std::vector<std::string> parametrsVector;
    boost::split(parametrsVector, parameters, boost::is_any_of(" "), boost::token_compress_on);

    if (parametrsVector.size() != 10)
    {
        cout << "invalid triangle arguments count\n";
        return nullptr;
    }

    CSimpleFillStyle fillStyle;
    CSimpleLineStyle lineStyle;

    if (parametrsVector[1] != "none")
    {
        fillStyle.SetColor((uint32_t)strtoull(parametrsVector[1].c_str(), NULL, 16));
    }
    if (parametrsVector[2] != "none")
    {
        lineStyle.SetColor((uint32_t)strtoull(parametrsVector[2].c_str(), NULL, 16));
    }

    lineStyle.SetWidth(stoi(parametrsVector[3]));

    CTriangle triangle(
        { stod(parametrsVector[4]), stod(parametrsVector[5]) }, 
        { stod(parametrsVector[6]), stod(parametrsVector[7]) }, 
        { stod(parametrsVector[8]), stod(parametrsVector[9]) },
        fillStyle,
        lineStyle
    );

    return make_shared<CTriangle>(triangle);
}

shared_ptr<IShape> CreateEllipse(const string& parameters)
{
    std::vector<std::string> parametrsVector;
    boost::split(parametrsVector, parameters, boost::is_any_of(" "), boost::token_compress_on);

    if (parametrsVector.size() != 8)
    {
        cout << "invalid ellipse arguments count\n";
        return nullptr;
    }

    CSimpleFillStyle fillStyle;
    CSimpleLineStyle lineStyle;

    if (parametrsVector[1] != "none")
    {
        fillStyle.SetColor((uint32_t)strtoull(parametrsVector[1].c_str(), NULL, 16));
    }
    if (parametrsVector[2] != "none")
    {
        lineStyle.SetColor((uint32_t)strtoull(parametrsVector[2].c_str(), NULL, 16));
    }
    lineStyle.SetWidth(stoi(parametrsVector[3]));

    CEllipse ellipse(
        { stod(parametrsVector[4]), stod(parametrsVector[5]) },
        stod(parametrsVector[6])/2, 
        stod(parametrsVector[7])/2 ,
        fillStyle,
        lineStyle
    );

    return make_shared<CEllipse>(ellipse);

}

shared_ptr<IShape> CreateRectangle(const string& parameters)
{
    std::vector<std::string> parametrsVector;
    boost::split(parametrsVector, parameters, boost::is_any_of(" "), boost::token_compress_on);

    if (parametrsVector.size() != 8)
    {
        cout << "invalid rectangle arguments count\n";
        return nullptr;
    }

    CSimpleFillStyle fillStyle;
    CSimpleLineStyle lineStyle;

    if (parametrsVector[1] != "none")
    {
        fillStyle.SetColor((uint32_t)strtoull(parametrsVector[1].c_str(), NULL, 16));
    }
    if (parametrsVector[2] != "none")
    {
        lineStyle.SetColor((uint32_t)strtoull(parametrsVector[2].c_str(), NULL, 16));
    }
    lineStyle.SetWidth(stoi(parametrsVector[3]));

    CRectangle rect(
        { stod(parametrsVector[4]), stod(parametrsVector[5]) },
        stod(parametrsVector[6]),
        stod(parametrsVector[7]),
        fillStyle,
        lineStyle
    );

    return make_shared<CRectangle>(rect);

}

shared_ptr<IShape> CreateComposite(const string& parameters);

map<string, function<shared_ptr<IShape>(const string& parameters)>> CREATE_SHAPES_FUNCTIONS
{
    {"rectangle", &CreateRectangle},
    {"triangle", &CreateTriangle},
    {"ellipse", &CreateEllipse},
    {"composite", &CreateComposite},
};

shared_ptr<IShape> CreateComposite(const string&)
{
    CGroupShape groupShape;
    string parameters;
    string type;
    while (cin >> type && type != "end" && getline(cin, parameters))
    {
        groupShape.InsertShape(CREATE_SHAPES_FUNCTIONS[type](parameters));
    }
    return make_shared<CGroupShape>(groupShape);

}
void DialogeWithUser(CCanvas& canvas, CSlide& slide)
{
    string parameters;
    string type;
    while (cin >> type && getline(cin, parameters))
    {
        slide.InsertShape(CREATE_SHAPES_FUNCTIONS[type](parameters));
    }
    slide.Draw(canvas);
}

int main()
{
    CSimpleLineStyle lineStyle;
    CCanvas canvas("example.svg", lineStyle);
    CSlide slide;
    DialogeWithUser(canvas, slide);
}
