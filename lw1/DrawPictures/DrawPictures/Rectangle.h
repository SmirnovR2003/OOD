#pragma once
#include "Shape.h"
#include <variant>

class Rectangle : public Shape
{
public:
	Rectangle(Point leftTop, double width, double height);
	std::map<std::string, std::variant<double, std::string>> GetInfoForDrawing() override;
	void MoveShape(double dx, double dy) override;
	void ShowInfo() override;
private:
	Point m_leftTop;
	double m_width;
	double m_height;
};

