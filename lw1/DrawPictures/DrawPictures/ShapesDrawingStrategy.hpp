#include "IDrawingStrategy.h"
#include "Circle.h"
#include "shapes.h"
#include "Line.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Text.h"
#include "Shape.h"
#include <variant>

class CircleDrawingStrategy : public IDrawingStrategy
{
public:
	void Draw(Canvas& canvas, std::map<std::string, std::variant<double, std::string>> shapeParameters, sf::Color color) override
	{
		canvas.DrawEllipse
		(
			std::get<double>(shapeParameters.find("cx")->second),
			std::get<double>(shapeParameters.find("cy")->second),
			std::get<double>(shapeParameters.find("rx")->second),
			std::get<double>(shapeParameters.find("ry")->second)
		);
	};
};

class LineDrawingStrategy : public IDrawingStrategy
{
public:
	void Draw(Canvas& canvas, std::map<std::string, std::variant<double, std::string>> shapeParameters, sf::Color color) override
	{
		std::vector<Point> points = 
		{ 
			{std::get<double>(shapeParameters.find("x1")->second), std::get<double>(shapeParameters.find("y1")->second)},
			{std::get<double>(shapeParameters.find("x2")->second), std::get<double>(shapeParameters.find("y2")->second)}
		};
		canvas.DrawPolygon(points);
	};
};

class RectangleDrawingStrategy : public IDrawingStrategy
{
public:
	void Draw(Canvas& canvas, std::map<std::string, std::variant<double, std::string>> shapeParameters, sf::Color color) override
	{
		std::vector<Point> points = 
		{
			{
				std::get<double>(shapeParameters.find("x")->second), 
				std::get<double>(shapeParameters.find("y")->second)},
			{
				std::get<double>(shapeParameters.find("x")->second) + std::get<double>(shapeParameters.find("width")->second),
				std::get<double>(shapeParameters.find("y")->second)
			},
			{
				std::get<double>(shapeParameters.find("x")->second) + std::get<double>(shapeParameters.find("width")->second),
				std::get<double>(shapeParameters.find("y")->second) + std::get<double>(shapeParameters.find("height")->second)
			},
			{
				std::get<double>(shapeParameters.find("x")->second), 
				std::get<double>(shapeParameters.find("y")->second) + std::get<double>(shapeParameters.find("height")->second)
			}
		};
		canvas.DrawPolygon(points);
	};
};

class TriangleDrawingStrategy : public IDrawingStrategy
{
public:
	void Draw(Canvas& canvas, std::map<std::string, std::variant<double, std::string>> shapeParameters, sf::Color color) override
	{
		std::vector<Point> points = 
		{
			{std::get<double>(shapeParameters.find("x1")->second), std::get<double>(shapeParameters.find("y1")->second)},
			{std::get<double>(shapeParameters.find("x2")->second), std::get<double>(shapeParameters.find("y2")->second)},
			{std::get<double>(shapeParameters.find("x3")->second), std::get<double>(shapeParameters.find("y3")->second)}
		};
		canvas.DrawPolygon(points);
	};
};

class TextDrawingStrategy : public IDrawingStrategy
{
public:
	void Draw(Canvas& canvas, std::map<std::string, std::variant<double, std::string>> shapeParameters, sf::Color color) override
	{

		canvas.DrawText(
			std::get<double>(shapeParameters.find("x")->second),
			std::get<double>(shapeParameters.find("y")->second),
			std::get<double>(shapeParameters.find("fontSize")->second),
			std::get<std::string>(shapeParameters.find("content")->second)
		);
	};
};


