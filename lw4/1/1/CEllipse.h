#pragma once
#include "CShape.h"
class CEllipse :
    public CShape
{
public:
    CEllipse(sf::Color& color, Vertex center, double rx, double ry)
        :CShape(color)
        ,m_center(center)
        ,m_rx(rx)
        ,m_ry(ry)
    {
    }

    Vertex GetCenter()
    {
        return m_center;
    }

    double GetVerticalRadius()
    {
        return m_ry;
    }

    double GetHorizontalRadius()
    {
        return m_rx;
    }

    void Draw(ICanvas* canvas)const override
    {
        canvas->SetColor(GetColor());
        canvas->DrawEllipse(m_center, m_rx, m_ry);
    }

private:
    Vertex m_center;
    double m_rx;
    double m_ry;
};

