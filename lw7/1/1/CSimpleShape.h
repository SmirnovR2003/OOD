#pragma once
#include "IShape.h"
#include "CSimpleFillStyle.h"
#include "CSimpleFillStyle.h"
#include "CSimpleLineStyle.h"
class CSimpleShape :
    public IShape
{
public:
	CSimpleShape(CSimpleFillStyle fillStyle, CSimpleLineStyle lineStyle)
		:m_fillStyle(fillStyle)
		, m_lineStyle(lineStyle)
	{}
	ILineStyle& GetOutlineStyle() override
	{
		return m_lineStyle;
	}
	const ILineStyle& GetOutlineStyle()const override
	{
		return m_lineStyle;
	}
	void SetOutlineColor(const std::optional<RGBAColor> color) override
	{
		m_lineStyle.SetColor(color);
	}
	void SetOutlineWidth(const uint8_t width) override
	{
		m_lineStyle.SetWidth(width);
	}

	IFillStyle& GetFillStyle() override
	{
		return m_fillStyle;
	}
	const IFillStyle& GetFillStyle()const override
	{
		return m_fillStyle;
	}
	void SetFillColor(const std::optional<RGBAColor> color) override
	{
		m_fillStyle.SetColor(color);
	}

	std::shared_ptr<IGroupShape> GetGroup() override
	{
		return nullptr;
	}
	std::shared_ptr<const IGroupShape> GetGroup() const override
	{
		return nullptr;
	}

private:
	CSimpleFillStyle m_fillStyle;
	CSimpleLineStyle m_lineStyle;

};

