#pragma once

#include<vector>
#include <memory>
#include "CShape.h"

class CPictureDraft
{
public:
	CPictureDraft(std::vector<std::shared_ptr<CShape>>& shapes)
		:m_shapes(shapes)
	{
	}

	size_t GetShapeCount()const
	{
		return m_shapes.size();
	}

	const CShape* GetShape(size_t index)const
	{
		if (index >= m_shapes.size())
		{
			throw std::invalid_argument("no shape with this index");
		}
		return m_shapes[index].get();
	}

private:
	std::vector<std::shared_ptr<CShape>> m_shapes;
};

