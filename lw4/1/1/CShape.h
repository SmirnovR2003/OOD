#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "ICanvas.h"

class CShape
{
public:
	CShape(sf::Color& color)
		:m_color(color)
	{
	}

	sf::Color GetColor()const
	{
		return m_color;
	}

	virtual void Draw(ICanvas* canvas)const = 0;
private:
	sf::Color m_color;
};

