#pragma once
#include "IModel.h"
#include <map>
#include <functional>
#include "CRandomStringGenerator.h"
class CModel :
    public IModel
{
public:
	void AddShape(ShapeType type) override
	{
		std::string id = CRandomStringGenerator().Get();
	}

	void RemoveShape(std::string id)override
	{
		m_shapes.erase(id);
	}

	void MoveShape(std::string id, Point leftTop)override
	{
		m_shapes[id].m_point = leftTop;
	}

	void ResizeShape(std::string id, Size newSize)override
	{
		m_shapes[id].m_size = newSize;
	}

private:
	std::map<std::string, Shape> m_shapes;
	const static std::map<ShapeType, std::function<void()>> M_CREATE_SHAPES_FUNCTIONS;


};

