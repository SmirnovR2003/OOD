#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "ICanvas.h"


int HexadecimalToDecimal(std::string hex) {
	size_t hexLength = hex.length();
	double dec = 0;

	for (size_t i = 0; i < hexLength; ++i)
	{
		char b = hex[i];

		if (b >= 48 && b <= 57)
			b -= 48;
		else if (b >= 65 && b <= 70)
			b -= 55;

		dec += b * pow(16, ((hexLength - i) - 1));
	}

	return (int)dec;
}

class CShape
{
public:
	CShape(sf::Color& color)
		:m_color(color)
	{
	}
	CShape(std::string& hexColor)
		:m_color(HexadecimalToDecimal(hexColor))
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

