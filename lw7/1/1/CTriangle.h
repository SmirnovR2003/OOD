#pragma once
#include "CSimpleShape.h"
#include <algorithm>
class CTriangle :
    public CSimpleShape
{
public:
	CTriangle(Point point1, Point point2, Point point3, CSimpleFillStyle& fillStyle, CSimpleLineStyle& lineStyle)
		:m_point1(point1)
		, m_point2(point2)
		, m_point3(point3)
		, CSimpleShape(fillStyle, lineStyle)
	{
	}

	std::optional<RectD> GetFrame()const override
	{
		double minX = std::min({ m_point1.x , m_point2.x , m_point3.x });
		double minY = std::min({ m_point1.y , m_point2.y , m_point3.y });
		double maxX = std::max({ m_point1.x , m_point2.x , m_point3.x });
		double maxY = std::max({ m_point1.y , m_point2.y , m_point3.y });
		std::optional<RectD> frame ( { minX, minY, maxX - minX, maxY - minY });
		return frame;
	}
	void SetFrame(const RectD& rect)override
	{
		RectD currentFrame = GetFrame().value();
		double magnificationFactorX = rect.width / currentFrame.width;
		double magnificationFactorY = rect.height / currentFrame.height;

		m_point1.x += (rect.left - currentFrame.left) * magnificationFactorX;
		m_point2.x += (rect.left - currentFrame.left) * magnificationFactorX;
		m_point3.x += (rect.left - currentFrame.left) * magnificationFactorX;

		m_point1.y += (rect.top - currentFrame.top) * magnificationFactorY;
		m_point2.y += (rect.top - currentFrame.top) * magnificationFactorY;
		m_point3.y += (rect.top - currentFrame.top) * magnificationFactorY;
	}
	void Draw(ICanvas& canvas)const override
	{
		canvas.SetLineStyle(GetOutlineStyle());
		if (GetFillStyle().GetColor() != std::nullopt)
		{
			canvas.BeginFill(GetFillStyle().GetColor().value());
		}
		canvas.MoveTo(m_point1.x, m_point1.y);
		canvas.LineTo(m_point2.x, m_point2.y);
		canvas.LineTo(m_point3.x, m_point3.y);
		canvas.LineTo(m_point1.x, m_point1.y);

		if (GetFillStyle().GetColor() != std::nullopt)
		{
			canvas.EndFill();
		}

	}
private:
	Point m_point1;
	Point m_point2;
	Point m_point3;
};

