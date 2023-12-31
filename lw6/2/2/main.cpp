﻿#include <iostream>
#include <stdexcept>
#include <string>
#include <boost/format.hpp>
#include "shape_drawing_lib.h"
#include "modern_graphics_lib.h"
#include "ModernGraphicsLibAdapter.h"

using namespace std;

// Пространство имен приложения (доступно для модификации)
namespace app
{
	void PaintPicture(shape_drawing_lib::CCanvasPainter& painter)
	{
		using namespace shape_drawing_lib;

		CTriangle triangle({ 10, 15 }, { 100, 200 }, { 150, 250 });
		CRectangle rectangle({ 30, 40 }, 18, 24);

		painter.Draw(triangle);
		painter.Draw(rectangle);
	}

	void PaintPictureOnCanvas()
	{
		graphics_lib::CCanvas simpleCanvas;
		shape_drawing_lib::CCanvasPainter painter(simpleCanvas);
		PaintPicture(painter);
	}

	void PaintPictureOnModernGraphicsRenderer()
	{
		modern_graphics_lib::CModernGraphicsRenderer renderer(cout);
		ModernGraphicsLibAdapter adaptRenderer(renderer);
		shape_drawing_lib::CCanvasPainter painter(adaptRenderer);
		PaintPicture(painter);
	}
}

int main()
{
	cout << "Should we use new API (y)?";
	string userInput;
	if (getline(cin, userInput) && (userInput == "y" || userInput == "Y"))
	{
		app::PaintPictureOnModernGraphicsRenderer();
	}
	else
	{
		app::PaintPictureOnCanvas();
	}

	return 0;
}
