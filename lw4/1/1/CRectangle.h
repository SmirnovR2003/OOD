#pragma once
#include "CShape.h"
class CRectangle :
    public CShape
{
public:
    CRectangle(sf::Color& color, Vertex m_leftTop, Vertex m_rightBottom)
        :CShape(color)
        , m_leftTop(m_leftTop)
        , m_rightBottom(m_rightBottom)
    {
    }

    Vertex GetLeftTop()
    {
        return m_leftTop;
    }

    Vertex GetRightBottom()
    {
        return m_rightBottom;
    }

    void Draw(ICanvas* canvas)const override
    {
        canvas->SetColor(GetColor());
        canvas->DrawLine({ m_leftTop }, { m_leftTop.x,  m_rightBottom .y});
        canvas->DrawLine({ m_leftTop.x,  m_rightBottom.y }, { m_rightBottom });
        canvas->DrawLine({ m_rightBottom }, { m_rightBottom.x,  m_leftTop.y});
        canvas->DrawLine({ m_rightBottom.x,  m_leftTop.y }, { m_leftTop });
    }

private:
    Vertex m_leftTop;
    Vertex m_rightBottom;
};

