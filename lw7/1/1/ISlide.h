#pragma once
#include "IGroupShape.h"
class ISlide
	: public IShapes
	, public IDrawable
{
public:
	virtual ~ISlide() = default;
};

