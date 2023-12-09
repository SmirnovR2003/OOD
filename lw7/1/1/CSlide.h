#pragma once
#include "ISlide.h"
#include <stdexcept>
class CSlide :
    public ISlide
{
public:
	size_t GetShapesCount()const override
	{
		return m_shapes.size();
	}
	void InsertShape(const std::shared_ptr<IShape>& shape, size_t position = std::numeric_limits<size_t>::max())override
	{
		if (position == std::numeric_limits<size_t>::max())
		{
			m_shapes.push_back(shape);
		}
		else
		{
			if (m_shapes.size() < position)
			{
				throw std::out_of_range("out of range");
			}

			m_shapes.insert(m_shapes.begin() + position, shape);
		}

	}
	std::shared_ptr<IShape> GetShapeAtIndex(size_t index)override
	{
		if (m_shapes.size() < index)
		{
			throw std::out_of_range("out of range");
		}
		return m_shapes[index];

	}
	void RemoveShapeAtIndex(size_t index)override
	{
		if (m_shapes.size() < index)
		{
			throw std::out_of_range("out of range");
		}
		m_shapes.erase(m_shapes.begin() + index);

	}

	void Draw(ICanvas& canvas)const override
	{
		for (auto& shape : m_shapes)
		{
			shape->Draw(canvas);
		}
	}
private:
	std::vector<std::shared_ptr<IShape>> m_shapes;
};

