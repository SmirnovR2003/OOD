#pragma once
#include"ILineStyle.h"


class CSimpleLineStyle : public ILineStyle
{
public:

	std::optional<RGBAColor> GetColor()const override
	{
		return m_color;
	}
	void SetColor(std::optional<RGBAColor> color)override
	{
		m_color = color;
	}

	std::optional<uint8_t> GetWidth()const override
	{
		if (m_color.has_value())
		{
			return m_outLineWidthWidth;
		}
		else
		{
			return std::nullopt;
		}
	}
	void SetWidth(uint8_t outLineWidth)override
	{
		m_outLineWidthWidth = outLineWidth;
	}

private:
	std::optional<RGBAColor> m_color = std::nullopt;
	uint8_t m_outLineWidthWidth = 0;

};

