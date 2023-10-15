#pragma once
#include <limits>
#include <iostream>
#include <sstream>
#include <string>
#include<cmath>

double PI = acos(-1.0);

struct Vector
{
	double x;
	double y;
};

Vector GetVectorByDirection(int direction)
{
	//перевести через sin и cos
	switch (direction)
	{
	case 90:
		return { 0, 1 };
	case 180:
		return { -1, 0 };
	case 270:
		return { 0, -1 };
	default:
		return { cos(direction), sin(direction) };
	}
}

class DefaultStat
{
public:
	//убрать вывод
	DefaultStat()
	{
	}
	void Update(double newStat)
	{
		if (m_minStat > newStat)
		{
			m_minStat = newStat;
		}
		if (m_maxStat < newStat)
		{
			m_maxStat = newStat;
		}
		m_accStat += newStat;
		++m_countAcc;
	}

	double GetMin()
	{
		return m_minStat;
	}

	double GetMax()
	{
		return m_maxStat;
	}

	double GetAverage()
	{
		return m_accStat / m_countAcc;
	}

private:
	double m_minStat = std::numeric_limits<double>::infinity();
	double m_maxStat = -std::numeric_limits<double>::infinity();
	double m_accStat = 0;
	unsigned m_countAcc = 0;
};

class WindDirectionStat
{
public:
	void Update(int direction)
	{
		Vector newVec = GetVectorByDirection(direction);
		m_vec.x += newVec.x;
		m_vec.y += newVec.y;

		m_direction = ((atan2(m_vec.y, m_vec.x) + PI) * 180 / PI);
	}

	bool IsAverageDirection()
	{
		return !(m_vec.x == 0 && m_vec.y == 0);
	}

	double GetAverageDirection()
	{
		return m_direction;
	}

private:
	double m_direction = 0;
	Vector m_vec{0,0};
};