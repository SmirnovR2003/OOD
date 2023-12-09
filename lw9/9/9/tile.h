#pragma once
#include <array>
#include <vector>
#include <cassert>

#include "geom.h"

class Tile
{
public:
	// Размер тайла 8*8 пикселей.
	constexpr static int SIZE = 8;

	// Конструктор по умолчанию. Заполняет тайл указанным цветом.
	Tile(uint32_t color = 0) noexcept
		:m_tile(std::vector<std::vector<uint32_t>>(SIZE, std::vector < uint32_t>(SIZE, color)))
	{
		// -------------- не удалять ------------
		assert(m_instanceCount >= 0);
		++m_instanceCount; // Увеличиваем счётчик тайлов (для целей тестирования).
		// -------------- не удалять ------------
	}

	Tile(const Tile& other)
	{
		m_tile = other.m_tile;

		// -------------- не удалять ------------
		assert(m_instanceCount >= 0);
		++m_instanceCount; // Увеличиваем счётчик тайлов (для целей тестирования).
		// -------------- не удалять ------------
	}

	~Tile()
	{
		// -------------- не удалять ------------
		--m_instanceCount; // Уменьшаем счётчик тайлов.
		assert(m_instanceCount >= 0);
		// -------------- не удалять ------------
	}

	/**
     * Изменяет цвет пикселя тайла.
     * Если координаты выходят за пределы тайла, метод ничего не делает.
     */
	void SetPixel(Point p, uint32_t color) noexcept
	{
		if (IsPointInSize(p, { SIZE,SIZE }))
		{
			m_tile[p.x][p.y] = color;
		}
	}

	/**
     * Возвращает цвет пикселя. Если координаты выходят за пределы тайла, возвращается пробел.
     */
	uint32_t GetPixel(Point p) const noexcept
	{
		if (IsPointInSize(p, { SIZE,SIZE }))
		{
			return m_tile[p.x][p.y];
		}
		else
		{
			return ' ';
		}
		
	}

	// Возвращает количество экземпляра класса Tile в программе.
	static int GetInstanceCount() noexcept
	{
		// -------------- не удалять ------------
		return m_instanceCount;
		// -------------- не удалять ------------
	}
	
	// Возвращает количество экземпляра класса Tile в программе.
	//static int GetInstanceCount() noexcept
	//{
	//	// -------------- не удалять ------------
	//	return m_instanceCount;
	//	// -------------- не удалять ------------
	//}

private:
	// -------------- не удалять ------------
	//static int m_instanceCount;
	//static int m_instanceCount;
	inline static int m_instanceCount = 0;
	// -------------- не удалять ------------

	std::vector<std::vector<uint32_t>> m_tile;

};
