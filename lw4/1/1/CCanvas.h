#pragma once
#include "ICanvas.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

class CCanvas :
    public ICanvas
{
public:

    //оставить размеры фигур такими же как и при рисовании после ресайза
    //принимать RenderTarget
    CCanvas(sf::RenderTarget* target)
       :m_canvas(target)
    {
    }

    void SetColor(sf::Color color)override
    {
        m_color = color;
    }

    void DrawLine(Vertex point1, Vertex point2) override
    {
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f((float)point1.x, (float)point1.y), m_color),
            sf::Vertex(sf::Vector2f((float)point2.x, (float)point2.y), m_color)
        };
        
        m_canvas->draw(line, 2, sf::Lines);
    }

    //сделать как в задании на диаграмме
    void DrawEllipse(Vertex center, double w, double h)override
    {
        const int POINT_COUNT = 200;
        sf::Vector2f ellipseRadius = { float(w/2), float(h/2) };

        sf::ConvexShape ellipse;

        ellipse.setPosition({ float(center.x), float(center.y) });
        ellipse.setPointCount(POINT_COUNT);

        ellipse.setOutlineThickness(2);
        ellipse.setOutlineColor(m_color);
        ellipse.setFillColor(sf::Color::Black);

        for (int pointNo = 0; pointNo < POINT_COUNT; pointNo++)
        {
            double angle = 2 * PI * pointNo / POINT_COUNT;
            sf::Vector2f point = {
                float(ellipseRadius.x * sin(angle)),
                float(ellipseRadius.y * cos(angle))
            };
            ellipse.setPoint(pointNo, point);
        }

        m_canvas->draw(ellipse);
    }

    //вынести в main отображение

private:
    sf::RenderTarget* m_canvas;
    sf::Color m_color;
};

