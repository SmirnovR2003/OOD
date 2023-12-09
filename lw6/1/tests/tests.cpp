#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include "../../../catch2/catch.hpp"
#include "../2/app.h"

using namespace std;

SCENARIO("test")
{
	ostringstream out;

	modern_graphics_lib::CModernGraphicsRenderer renderer(out);
	ModernGraphicsLibAdapter adaptRenderer(renderer);
	shape_drawing_lib::CCanvasPainter painter(adaptRenderer);
	renderer.BeginDraw();
	app::PaintPicture(painter);
	renderer.EndDraw();


	CHECK(out.str() == "<draw>\n"
		"  <line fromX=\"10\" fromY=\"15\" toX=\"100\" toY=\"200\"/>\n"
		"  <line fromX=\"100\" fromY=\"200\" toX=\"150\" toY=\"250\"/>\n"
		"  <line fromX=\"150\" fromY=\"250\" toX=\"10\" toY=\"15\"/>\n"
		"  <line fromX=\"30\" fromY=\"40\" toX=\"48\" toY=\"40\"/>\n"
		"  <line fromX=\"48\" fromY=\"40\" toX=\"48\" toY=\"64\"/>\n"
		"  <line fromX=\"48\" fromY=\"64\" toX=\"30\" toY=\"64\"/>\n"
		"  <line fromX=\"30\" fromY=\"64\" toX=\"30\" toY=\"40\"/>\n"
		"</draw>\n");
}