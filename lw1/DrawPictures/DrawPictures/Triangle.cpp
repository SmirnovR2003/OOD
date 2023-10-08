#include "Triangle.h"
#include <iostream>

Triangle::Triangle(Point point1, Point point2, Point point3)
	:m_point1(point1)
	,m_point2(point2)
	,m_point3(point3)
{
}

std::map<std::string, std::variant<double, std::string>> Triangle::GetInfoForDrawing()
{
	return 
	{
		{"x1", m_point1.x},
		{"y1", m_point1.y},
		{"x2", m_point2.x},
		{"y2", m_point2.y},
		{"x3", m_point3.x},
		{"y3", m_point3.y},
	};
}

void Triangle::MoveShape(double dx, double dy)
{
	m_point1.x += dx;
	m_point1.y += dy;
	m_point2.x += dx;
	m_point2.y += dy;
	m_point3.x += dx;
	m_point3.y += dy;
}

void Triangle::ShowInfo()
{
	std::cout << m_point1.x << " " << m_point1.y << " " << m_point2.x << " " << m_point2.y << " " << m_point3.x << " " << m_point3.y;
}
