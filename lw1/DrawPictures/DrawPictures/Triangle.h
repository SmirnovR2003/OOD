#pragma once
#include "Shape.h"
#include <variant>
class Triangle :
    public Shape
{
public:
    Triangle(Point point1, Point point2, Point point3);
    std::map<std::string, std::variant<double, std::string>> GetInfoForDrawing() override;
    void MoveShape(double dx, double dy) override;
    void ShowInfo() override;
private:
    Point m_point1;
    Point m_point2;
    Point m_point3;
};

