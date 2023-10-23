#pragma once
#include <SFML/Graphics.hpp>

struct Vertex
{
	double x;
	double y;
};

const double PI = 3.141592653589793238463;

class ICanvas
{
public:
	virtual void SetColor(sf::Color color) = 0;
	virtual void DrawLine(Vertex point1, Vertex point2) = 0;
	virtual void DrawEllipse(Vertex center, double rx, double ry) = 0;

};

