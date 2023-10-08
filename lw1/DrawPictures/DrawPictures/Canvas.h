#pragma once

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

struct Point
{
	double x;
	double y;
};

namespace gfx
{
	struct ICanvas
	{
	public:
		virtual void SetColor(sf::Color c){};
		virtual void MoveTo(double x, double y){};
		virtual void LineTo(double x, double y){};
		virtual void DrawEllipse(double cx, double cy, double rx, double ry) {};
		virtual void DrawText(double left, double top, double fontSize, const std::string& text) {};
		virtual void DrawPolygon(std::vector<Point> points){};
	};

}

class Canvas : public gfx::ICanvas
{
public:
	Canvas();
	void SetColor(sf::Color c)override;
	void MoveTo(double x, double y)override;
	void LineTo(double x, double y)override;
	void DrawEllipse(double cx, double cy, double rx, double ry)override;
	void DrawText(double left, double top, double fontSize, const std::string& text)override;
	void DrawPolygon(std::vector<Point> points)override;
	void Display();
	void ShowFinalPicture();
private:
	sf::RenderWindow m_canvas;
	sf::Color m_color;
	Point m_currentPoint;
};

