#include "Text.h"
#include <iostream>

Text::Text(std::string content, double fontSize, Point leftTop)
	:m_content(content)
	,m_fontSize(fontSize)
	,m_leftTop(leftTop)
{
	m_font.loadFromFile("TimesNewRomanPSMT.ttf");
}

void Text::MoveShape(double dx, double dy)
{
	m_leftTop.x += dx;
	m_leftTop.y += dy;
}

void Text::ShowInfo()
{
	std::cout << m_leftTop.x << " " << m_leftTop.y << " " << m_fontSize << " " << m_content;
}

std::map<std::string, std::variant<double, std::string>> Text::GetInfoForDrawing()
{
	return 
	{
		{"x", m_leftTop.x},
		{"y", m_leftTop.y},
		{"fontSize", m_fontSize},
		{"content", m_content},
	};
}
