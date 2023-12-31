#pragma once
#include "CPictureDraft.h"
#include"IShapeFactory.h"
#include<string>

class CDesigner 
{
public:
    CDesigner(std::unique_ptr<IShapeFactory> shapeFactory)
        :m_shapeFactory(move(shapeFactory))
    {
    }

    CPictureDraft CreateDraft(std::istream& strm) 
    {
        std::string shapeDescr;
        std::vector<std::shared_ptr<CShape>> shapes;
        while (getline(strm, shapeDescr))
        {
            shapes.push_back(m_shapeFactory->CreateShape(shapeDescr));
        }
        return shapes;
    }

private:

    std::unique_ptr<IShapeFactory> m_shapeFactory;

};

