#pragma once
#include"CSimpleShape.h"
class CRectangle :
    public CSimpleShape
{
public:
	CRectangle(Point leftTop, double width, double height, CSimpleFillStyle& fillStyle, CSimpleLineStyle& lineStyle)
		:m_leftTop(leftTop)
		, m_width(width)
		, m_height(height)
		, CSimpleShape(fillStyle, lineStyle)
	{
	}

	std::optional<RectD> GetFrame()const override
	{
		std::optional<RectD> frame({ m_leftTop.x, m_leftTop.y,  m_width , m_height });
		return frame;
	}
	void SetFrame(const RectD& rect)override
	{
		m_leftTop.x = rect.left;
		m_leftTop.y = rect.top;
		m_width = rect.width;
		m_height = rect.height;
	}
	void Draw(ICanvas& canvas)const override
	{
		canvas.SetLineStyle(GetOutlineStyle());
		if (GetFillStyle().GetColor() != std::nullopt)
		{
			canvas.BeginFill(GetFillStyle().GetColor().value());
		}
		canvas.MoveTo(m_leftTop.x, m_leftTop.y);
		canvas.LineTo(m_leftTop.x + m_width, m_leftTop.y);
		canvas.LineTo(m_leftTop.x + m_width, m_leftTop.y + m_height);
		canvas.LineTo(m_leftTop.x, m_leftTop.y + m_height);
		canvas.LineTo(m_leftTop.x, m_leftTop.y);

		if (GetFillStyle().GetColor() != std::nullopt)
		{
			canvas.EndFill();
		}

	}
private:
	Point m_leftTop;
	double m_width;
	double m_height;
};

