#pragma once
#include "shapes.h"
class Line :
    public Shape
{
public:
    Line(Point point1, Point point2);
    std::map<std::string, std::variant<double, std::string>> GetInfoForDrawing() override;
    void MoveShape(double dx, double dy) override;
    void ShowInfo() override;
private:
    Point m_point1;
    Point m_point2;
};

