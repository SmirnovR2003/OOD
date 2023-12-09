#pragma once
#include "ICanvas.h"
#include <fstream>
#include "IFillStyle.h"

class CCanvas :
    public ICanvas
{
public:
	CCanvas(const char* fileName, ILineStyle& lineStyle)
		:m_file(fileName)
		,m_lineStyle(lineStyle)
	{
		m_file << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"2000\" height=\"2000\">\n";
	}

	void SetLineStyle(const ILineStyle& style)override
	{
		m_lineStyle.SetColor(style.GetColor());
		m_lineStyle.SetWidth(style.GetWidth().has_value() ? style.GetWidth().value() : 0);
	}
	void BeginFill(RGBAColor color)override
	{
		if (m_isBeginFill)
		{
			throw std::logic_error("Fill already begun");
		}
		m_isBeginFill = true;
		uint8_t alpha = (color >> 24) & 0xFF; // Extract the alpha component of color1
		uint8_t red = (color >> 16) & 0xFF; // Extract the red component of color1
		uint8_t green = (color >> 8) & 0xFF; // Extract the green component of color1
		uint8_t blue = color & 0xFF; // Extract the blue component of color1

		m_file << "<path fill=\"rgba(" << (int)red <<", " << (int)green << ", " << (int)blue << ", " << (int)alpha << ")\"\n";

		if (m_lineStyle.GetColor().has_value())
		{
			m_file << " stroke-width=\"" << (int)m_lineStyle.GetWidth().value() << "\" stroke=\"rgba("
				<< (int)((m_lineStyle.GetColor().value() >> 16) & 0xFF)
				<< ", " << (int)((m_lineStyle.GetColor().value() >> 8) & 0xFF)
				<< ", " << (int)((m_lineStyle.GetColor().value()) & 0xFF)
				<< ", " << (int)((m_lineStyle.GetColor().value() >> 24) & 0xFF) << ")\"\n";

		}
		m_file << "d=\"" << "\n";
		
	}
	void EndFill()override
	{
		if (!m_isBeginFill)
		{
			throw std::logic_error("Fill not begun yet");
		}
		m_file << "\"/>\n";
		m_isBeginFill = false;
	}

	void MoveTo(double x, double y)override
	{
		m_x = x;
		m_y = y;

		if (m_isBeginFill)
		{
			m_file << "M " << m_x << ", " << m_y << "\n";

		}
	}

	void LineTo(double x, double y)override
	{
		m_x = x;
		m_y = y;
		if (m_isBeginFill)
		{
			m_file << "L " << m_x << ", " << m_y << "\n";
		}
		else
		{
			m_file << "<line x1 = " << m_x << " y1 = " << m_y << " x2 = " << x << " y2 = " << y;
			if (m_lineStyle.GetColor().has_value())
			{
				m_file << " stroke-width=\"" << (int)m_lineStyle.GetWidth().value() << "\" stroke=\"rgba("
					<< (int)((m_lineStyle.GetColor().value() >> 16) & 0xFF)
					<< ", " << (int)((m_lineStyle.GetColor().value() >> 8) & 0xFF)
					<< ", " << (int)((m_lineStyle.GetColor().value()) & 0xFF)
					<< ", " << (int)((m_lineStyle.GetColor().value() >> 24) & 0xFF) << ")\"\n";

			}
			m_file << "/>\n";
		}


	}

	void DrawEllipse(double left, double top, double width, double height)override
	{
		if (m_isBeginFill)
		{
			m_file << "M " << left + width/2 << ", " << top + height/2 << "\n";
			m_file << "a " << width / 2 << ", " << height / 2 << " 0 1,0 1,0\n";
		}
		else
		{
			m_file << "<ellipse  cx = " << left + width / 2 << " cy = " << top + height / 2 << " rx = " << width / 2 << " ry = " << height / 2;
			if (m_lineStyle.GetColor().has_value())
			{
				m_file << " stroke-width=\"" << m_lineStyle.GetWidth().value() << "\" stroke=\"rgba("
					<< (int)((m_lineStyle.GetColor().value() >> 16) & 0xFF)
					<< ", " << (int)((m_lineStyle.GetColor().value() >> 8) & 0xFF)
					<< ", " << (int)((m_lineStyle.GetColor().value()) & 0xFF)
					<< ", " << (int)((m_lineStyle.GetColor().value() >> 24) & 0xFF) << ")\"\n";

			}
			m_file << "/>\n";
		}

	}

	~CCanvas()
	{
		//убрать в отдельный метод
		m_file << "</svg>\n";
	}

private:
	double m_x = 0;
	double m_y = 0;
	bool m_isBeginFill = false;
	ILineStyle& m_lineStyle;
	std::ofstream m_file;

};

