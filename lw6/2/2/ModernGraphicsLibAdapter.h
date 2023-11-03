#include "grahics_lib.h"
#include "modern_graphics_lib.h"
#include "modern_graphics_lib.h"
#pragma once
class ModernGraphicsLibAdapter : 
	public graphics_lib::ICanvas,
	public modern_graphics_lib::CModernGraphicsRenderer
{
public:
	ModernGraphicsLibAdapter(std::ostream& strm)
		:modern_graphics_lib::CModernGraphicsRenderer(strm)
	{
		CModernGraphicsRenderer::BeginDraw();
	}
	void MoveTo(int x, int y) override
	{
		m_x = x;
		m_y = y;
	}
	void LineTo(int x, int y) override
	{
		CModernGraphicsRenderer::DrawLine({ m_x, m_y }, { x,y });
		m_x = x;
		m_y = y;

	}
	~ModernGraphicsLibAdapter()
	{
		CModernGraphicsRenderer::EndDraw();
	}
private:
	int m_x = 0;
	int m_y = 0;
};