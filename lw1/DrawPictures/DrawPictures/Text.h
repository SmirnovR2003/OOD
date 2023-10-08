#pragma once
#include "Shape.h"
class Text :
    public Shape
{
public:
    Text(std::string content, double fontSize, Point leftTop);
    void MoveShape(double dx, double dy) override;
    void ShowInfo() override;
    std::map<std::string, std::variant<double, std::string>> GetInfoForDrawing() override;

private:
    std::string m_content;
    double m_fontSize;
    Point m_leftTop;
    sf::Font m_font;
};

