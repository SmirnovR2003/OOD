#pragma once
#include "grahics_lib.h"
#include "modern_graphics_lib.h"
#include "modern_graphics_lib.h"
class ModernGraphicsLibClassAdapter :
	public graphics_lib::ICanvas,
	private modern_graphics_lib::CModernGraphicsRenderer
{
public:
	ModernGraphicsLibClassAdapter(std::ostream& strm)
		:modern_graphics_lib::CModernGraphicsRenderer(strm)
		, m_rgbColor(0, 0, 0, 1)
	{
		CModernGraphicsRenderer::BeginDraw();
	}
	void SetColor(uint32_t rgbColor)
	{
		m_rgbColor.r = (static_cast<float>((rgbColor >> 16) & 0xff) / 255);
		m_rgbColor.g = (static_cast<float>((rgbColor >> 8) & 0xff) / 255);
		m_rgbColor.b = (static_cast<float>((rgbColor & 0xff)) / 255);
	}
	void MoveTo(int x, int y) override
	{
		m_x = x;
		m_y = y;
	}
	void LineTo(int x, int y) override
	{
		CModernGraphicsRenderer::DrawLine({ m_x, m_y }, { x,y }, m_rgbColor);
		m_x = x;
		m_y = y;

	}
	~ModernGraphicsLibClassAdapter()
	{
		CModernGraphicsRenderer::EndDraw();
	}
private:
	int m_x = 0;
	int m_y = 0;
	modern_graphics_lib::CRGBAColor m_rgbColor;
};

