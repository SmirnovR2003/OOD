#pragma once
#include "ICanvas.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

class CCanvas :
    public ICanvas
{
public:
    CCanvas(sf::RenderWindow* target)
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
            sf::Vertex(sf::Vector2f(point1.x, point1.y), m_color),
            sf::Vertex(sf::Vector2f(point2.x, point2.y), m_color)
        };
        
        m_canvas->draw(line, 2, sf::Lines);
    }

    void DrawEllipse(Vertex center, double rx, double ry)override
    {
        const int POINT_COUNT = 200;
        sf::Vector2f ellipseRadius = { float(rx), float(ry) };

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

    void ShowFinalPicture()
    {
        while (m_canvas->isOpen())
        {
            sf::Event event;
            

            if (m_canvas->pollEvent(event) && event.type == sf::Event::Closed)
                m_canvas->close();


            m_canvas->display();
        }
    }

private:
    sf::RenderWindow* m_canvas;
    sf::Color m_color;
};

