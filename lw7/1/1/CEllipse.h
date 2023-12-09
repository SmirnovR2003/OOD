#pragma once
#include "CSimpleShape.h"
class CEllipse :
    public CSimpleShape
{
public:
	CEllipse(Point center, double rx, double ry, CSimpleFillStyle& fillStyle, CSimpleLineStyle& lineStyle)
		:m_center(center)
		, m_rx(rx)
		, m_ry(ry)
		, CSimpleShape(fillStyle, lineStyle)
	{
	}

	std::optional<RectD> GetFrame()const override
	{
		std::optional<RectD> frame({ m_center.x - m_rx, m_center.y - m_ry, m_rx * 2, m_ry * 2 });
		return frame;
	}

	void SetFrame(const RectD& rect)override
	{
		m_center.x = rect.left + rect.width / 2;
		m_center.y = rect.top + rect.height / 2;

		m_rx = rect.width / 2;
		m_ry = rect.height / 2;
	}

	void Draw(ICanvas& canvas)const override
	{
		canvas.SetLineStyle(GetOutlineStyle());
		if (GetFillStyle().GetColor() != std::nullopt)
		{
			canvas.BeginFill(GetFillStyle().GetColor().value());
		}
		canvas.DrawEllipse(m_center.x, m_center.y, m_rx * 2, m_ry * 2);
		if (GetFillStyle().GetColor() != std::nullopt)
		{
			canvas.EndFill();
		}
	}
private:
	Point m_center;
	double m_rx;
	double m_ry;
};

