#pragma once
#include<cmath>
#include "CShape.h"


class CRegularPolygon :
    public CShape
{
public:
    CRegularPolygon(sf::Color& color, Vertex center, double radius, unsigned int vertexCount)
        :CShape(color)
        , m_center(center)
        , m_radius(radius)
        , m_vertexCount(vertexCount)
    {}

    Vertex GetCenter()
    {
        return m_center;
    }

    double GetRadius()
    {
        return m_radius;
    }

    unsigned int GetVertexCount()
    {
        return m_vertexCount;
    }

    void Draw(ICanvas* canvas) const override
    {
        canvas->SetColor(GetColor());

        for (unsigned int i = 0; i < m_vertexCount; i++)
        {
            canvas->DrawLine(
                { 
                    m_center.x + m_radius * std::cos(2 * PI * i / m_vertexCount - PI / 2),
                    m_center.y + m_radius * std::sin(2 * PI * i / m_vertexCount - PI / 2)
                },
                { 
                    m_center.x + m_radius * std::cos(2 * PI * (i + 1) / m_vertexCount - PI / 2),
                    m_center.y + m_radius * std::sin(2 * PI * (i + 1) / m_vertexCount - PI / 2)
                }
            );
        }
    }

private:
    Vertex m_center;
    double m_radius;
    unsigned int m_vertexCount;
};

