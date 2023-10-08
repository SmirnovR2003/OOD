#include "Canvas.h"
#include <cmath>
#include <corecrt_math_defines.h>

Canvas::Canvas()
	:m_canvas(sf::RenderWindow(sf::VideoMode(800, 800), "Picture.png"))
	,m_currentPoint({0,0})
{
}

void Canvas::SetColor(sf::Color c)
{
	m_color = c;
}

void Canvas::MoveTo(double x, double y)
{
	m_currentPoint = { x,y };
}

void Canvas::LineTo(double x, double y)
{
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(m_currentPoint.x, m_currentPoint.y)),
		sf::Vertex(sf::Vector2f(x, y))
	};

	MoveTo(x, y);

	m_canvas.draw(line, 2, sf::Lines);
	//m_canvas.display();
}

void Canvas::DrawEllipse(double cx, double cy, double rx, double ry)
{
	const int POINT_COUNT = 200;
	sf::Vector2f ellipseRadius = { float(rx), float(ry) };

	sf::ConvexShape ellipse;

	ellipse.setPosition({ float(cx), float(cy) });
	ellipse.setPointCount(POINT_COUNT);
	ellipse.setFillColor(m_color);

	for (int pointNo = 0; pointNo < POINT_COUNT; pointNo++)
	{
		double angle = 2 * M_PI * pointNo / POINT_COUNT;
		sf::Vector2f point = {
			float(ellipseRadius.x * sin(angle)),
			float(ellipseRadius.y * cos(angle))
		};
		ellipse.setPoint(pointNo, point);
	}

	m_canvas.draw(ellipse);
	//m_canvas.display();

}

void Canvas::DrawText(double left, double top, double fontSize, const std::string& text)
{
	sf::Text textShape;
	sf::Font font;
	font.loadFromFile("TimesNewRomanPSMT.ttf");
	textShape.setString(text);
	textShape.setFont(font);
	textShape.setCharacterSize(fontSize);
	textShape.setPosition(left, top);
	textShape.setFillColor(m_color);

	m_canvas.draw(textShape);
	//m_canvas.display();
}

void Canvas::DrawPolygon(std::vector<Point> points)
{
	sf::ConvexShape convex;

	convex.setPointCount(points.size());

	for (int i = 0; i < points.size(); i++)
	{
		convex.setPoint(i, sf::Vector2f(points[i].x, points[i].y));
	}
	convex.setFillColor(m_color);
	m_canvas.draw(convex);
	//m_canvas.display();
}

void Canvas::Display()
{
	//m_canvas.display();
}
void Canvas::ShowFinalPicture()
{
	while (m_canvas.isOpen())
	{
		sf::Event event;
		while (m_canvas.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_canvas.close();
		}

		m_canvas.display();
	}
}
//
//bool Canvas::IsOpenWindow()
//{
//	bool isOpen = m_canvas.isOpen();
//	return isOpen;
//}