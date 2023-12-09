#pragma once
#include <cstdint>

template <typename T>
struct Rect
{
	T left;
	T top;
	T width;
	T height;
};

typedef Rect<double> RectD;
typedef uint32_t RGBAColor;

struct Point
{
	double x;
	double y;
};
