#pragma once
#include "ILineStyle.h"
#include "ILineStyleEnumerator.h"
#include <memory>
class CCompositeLineStyle :
    public ILineStyle
{
public:
	CCompositeLineStyle(ILineStyleEnumerator* lineStyleEnumerator)
		:m_lineStyleEnumerator(lineStyleEnumerator)
	{

	}

	std::optional<RGBAColor> GetColor()const override
	{
		std::optional<RGBAColor> color = std::nullopt;
		bool isFirst = true;
		m_lineStyleEnumerator->EnumerateAllLineStyles([&color, &isFirst](ILineStyle& style) {
			std::optional<RGBAColor> c = style.GetColor();

			if (isFirst)
			{
				color = c;
				isFirst = false;
			}
			else if (color != c)
			{
				color = std::nullopt;
			}
			
			});
		return color;
	}
	void SetColor(std::optional<RGBAColor> color)override
	{
		m_lineStyleEnumerator->EnumerateAllLineStyles([&color](ILineStyle& style) {
			style.SetColor(color);
			});
	}

	std::optional<uint8_t> GetWidth()const override
	{
		std::optional<uint8_t> width = std::nullopt;
		bool isFirst = true;
		m_lineStyleEnumerator->EnumerateAllLineStyles([&width, &isFirst](ILineStyle& style) {
			std::optional<uint8_t> w = style.GetWidth();

			if (isFirst)
			{
				width = w;
				isFirst = false;
			}
			else if (width != w)
			{
				width = std::nullopt;
			}
			

			});
		return width;
	}
	void SetWidth(uint8_t outLineWidth)override
	{
		m_lineStyleEnumerator->EnumerateAllLineStyles([&outLineWidth](ILineStyle& style) {
			style.SetWidth(outLineWidth);
			});

	}
private:
	ILineStyleEnumerator* m_lineStyleEnumerator;
};


