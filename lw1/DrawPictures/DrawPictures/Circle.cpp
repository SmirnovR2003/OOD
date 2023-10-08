#include "Circle.h"
#include <iostream>

Circle::Circle(Point center, double radius)
	:m_center(center)
	,m_radius(radius)
{
}

std::map<std::string, std::variant<double, std::string>> Circle::GetInfoForDrawing()
{
	return 
	{ 
		{"cx", m_center.x}, 
		{"cy", m_center.y}, 
		{"rx", m_radius},
		{"ry", m_radius},
	};
}

void Circle::MoveShape(double dx, double dy)
{
	m_center.x += dx;
	m_center.y += dy;
}

void Circle::ShowInfo()
{
	std::cout << m_center.x << " " << m_center.y << " " << m_radius;
}

