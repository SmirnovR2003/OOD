#include "grahics_lib.h"
#include "modern_graphics_lib.h"
#include "modern_graphics_lib.h"
#pragma once
class ModernGraphicsLibAdapter : 
	public graphics_lib::ICanvas
{
public:
	ModernGraphicsLibAdapter(modern_graphics_lib::CModernGraphicsRenderer& modernLib)
		:m_modernLib(modernLib)
	{
	}
	void MoveTo(int x, int y) override
	{
		m_x = x;
		m_y = y;
	}
	void LineTo(int x, int y) override
	{
		m_modernLib.DrawLine({ m_x, m_y }, { x,y });
		m_x = x;
		m_y = y;

	}
private:
	modern_graphics_lib::CModernGraphicsRenderer& m_modernLib;
	int m_x = 0;
	int m_y = 0;
};