#include "Shape.h"
#include <map>
#include "ShapesDrawingStrategy.hpp"

const std::map<std::string, IDrawingStrategy> DRRAWING_STRATEGY
{
	{"circle", CircleDrawingStrategy()},
	{"triangle", TriangleDrawingStrategy()},
	{"rectangle", RectangleDrawingStrategy()},
	{"text", TextDrawingStrategy()},
	{"line", LineDrawingStrategy()}
};

