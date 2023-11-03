#include "grahics_lib.h"
#include "modern_graphics_lib.h"
#pragma once
class ModernGraphicsLibAdapter : 
	public graphics_lib::ICanvas
{
public:
	ModernGraphicsLibAdapter(modern_graphics_lib::CModernGraphicsRenderer& modernLib)
		: m_rgbColor(0, 0, 0, 1)
		, m_modernLib(modernLib)
	{
		m_modernLib.BeginDraw();
	}
	void SetColor(uint32_t rgbColor)
	{
		m_rgbColor.r = static_cast<float>((rgbColor >> 16) & 0xff); 
		m_rgbColor.g = static_cast<float>((rgbColor >> 8) & 0xff); 
		m_rgbColor.b = static_cast<float>(rgbColor & 0xff); 
	}
	void MoveTo(int x, int y) override
	{
		m_x = x;
		m_y = y;
	}
	void LineTo(int x, int y) override
	{
		m_modernLib.DrawLine({ m_x, m_y }, { x,y }, m_rgbColor);
		m_x = x;
		m_y = y;

	}
	~ModernGraphicsLibAdapter()
	{
		m_modernLib.EndDraw();
	}
private:
	modern_graphics_lib::CModernGraphicsRenderer& m_modernLib;
	int m_x = 0;
	int m_y = 0;
	modern_graphics_lib::CRGBAColor m_rgbColor;
};