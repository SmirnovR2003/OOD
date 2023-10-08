#pragma once
#include "Shape.h"
#include <variant>
struct IDrawingStrategy
{
public:
	virtual void  Draw(Canvas& canvas, std::map<std::string, std::variant<double, std::string>> shapeParameters, sf::Color color) {};
	~IDrawingStrategy() {};
};