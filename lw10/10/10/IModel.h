#pragma once
#include<string>
#include "Resourses.h"


class IModel
{
	void virtual AddShape(ShapeType type) = 0;
	void virtual RemoveShape(std::string id) = 0;
	void virtual MoveShape(std::string id, Point leftTop) = 0;
	void virtual ResizeShape(std::string id, Size newSize) = 0;

	virtual ~IModel() = default;
};

