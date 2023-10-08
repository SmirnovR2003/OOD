#include "Line.h"
#include <iostream>

Line::Line(Point point1, Point point2)
	:m_point1(point1)
	,m_point2(point2)
{
}

std::map<std::string, std::variant<double, std::string>> Line::GetInfoForDrawing()
{
	return 
	{
		{"x1", m_point1.x},
		{"y1", m_point1.y},
		{"x2", m_point2.x},
		{"y2", m_point2.y}
	};
}

void Line::MoveShape(double dx, double dy)
{
	m_point1.x += dx;
	m_point1.y += dy;
	m_point2.x += dx;
	m_point2.y += dy;
}

void Line::ShowInfo()
{
	std::cout << m_point1.x << " " << m_point1.y << " " << m_point2.x << " " << m_point2.y;
}
