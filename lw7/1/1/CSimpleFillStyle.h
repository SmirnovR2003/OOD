#pragma once
#include "IFillStyle.h"

class CSimpleFillStyle : public IFillStyle
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

private:
	std::optional<RGBAColor> m_color = std::nullopt;
};
