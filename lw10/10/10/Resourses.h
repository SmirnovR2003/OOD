#pragma once

enum class ShapeType
{
	Triangle = 0,
	Rectangle,
	Ellipse
};

struct Point
{
	int x;
	int y;
};

struct Size
{
	int width;
	int height;
};

struct Shape
{
	Point m_point;
	Size m_size;
};
