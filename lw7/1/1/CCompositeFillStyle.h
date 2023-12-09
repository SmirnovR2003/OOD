#pragma once
#include "IFillStyle.h"
#include<memory>
#include "IFillStyleEnumerator.h"
class CCompositeFillStyle :
    public IFillStyle
{
public:
	CCompositeFillStyle(IFillStyleEnumerator* fillStyleEnumerator)
		:m_fillStyleEnumerator(fillStyleEnumerator)
	{

	}

	std::optional<RGBAColor> GetColor()const override
	{
		std::optional<RGBAColor> color = std::nullopt;
		bool isFirst = true;
		m_fillStyleEnumerator->EnumerateAllFillStyles([&color, &isFirst](IFillStyle& style) {
			std::optional<RGBAColor> c = style.GetColor();

			if (isFirst)
			{
				color = c;
				isFirst = false;
			}
			else
			{
				if (color != c)
				{
					color = std::nullopt;
				}
			}

			});
		return color;
	}
	void SetColor(std::optional<RGBAColor> color) override
	{
		m_fillStyleEnumerator->EnumerateAllFillStyles([&color](IFillStyle& style) {
			style.SetColor(color);
			});

	}
private:
	IFillStyleEnumerator* m_fillStyleEnumerator;
};

