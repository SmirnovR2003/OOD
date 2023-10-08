#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(Point leftTop, double width, double height)
    :m_leftTop(leftTop)
    ,m_width(width)
    ,m_height(height)
{
}

std::map<std::string, std::variant<double, std::string>> Rectangle::GetInfoForDrawing()
{
    return
    {
        {"x", m_leftTop.x},
        {"y", m_leftTop.y},
        {"width", m_width},
        {"height", m_height},
    };
}

void Rectangle::MoveShape(double dx, double dy)
{
    m_leftTop.x += dx;
    m_leftTop.y += dy;
}

void Rectangle::ShowInfo()
{
    std::cout << m_leftTop.x << " " << m_leftTop.y << " " << m_width << " " << m_height;
}
