#pragma once
#include "C:\roman\C++\ood\lw4\1\1\CShape.h"
class CMockTriangle :
    public CShape
{
    CMockTriangle(sf::Color& color, Vertex vertex1, Vertex vertex2, Vertex vertex3)
        :CShape(color)
        , m_vertex1(vertex1)
        , m_vertex2(vertex2)
        , m_vertex3(vertex3)
    {}

    Vertex GetPoint1()
    {
        return m_vertex1;
    }

    Vertex GetPoint2()
    {
        return m_vertex2;
    }

    Vertex GetPoint3()
    {
        return m_vertex3;
    }

    void Draw(ICanvas* canvas)const override
    {
        canvas->SetColor(GetColor());
        canvas->DrawLine(m_vertex1, m_vertex2);
        canvas->DrawLine(m_vertex2, m_vertex3);
        canvas->DrawLine(m_vertex3, m_vertex1);
    }

private:
    Vertex m_vertex1;
    Vertex m_vertex2;
    Vertex m_vertex3;
};

