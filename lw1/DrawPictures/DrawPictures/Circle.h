#pragma once
#include "Shape.h"
#include "IDrawingStrategy.h"

class Circle : public Shape
{
public:
	Circle(Point center, double radius);
	std::map<std::string, std::variant<double, std::string>> GetInfoForDrawing() override;
	void MoveShape(double dx, double dy) override;
	void ShowInfo() override;
private:
	Point m_center;
	double m_radius;
};

