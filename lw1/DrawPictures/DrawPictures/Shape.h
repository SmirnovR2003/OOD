#pragma once
#include <string>
#include <map>
#include <variant>
#include "Canvas.h"

class Shape
{
public:
	virtual std::map<std::string, std::variant<double, std::string>> GetInfoForDrawing() = 0;
	virtual void MoveShape(double dx, double dy) = 0;
	virtual void ShowInfo() = 0;

private:
};

