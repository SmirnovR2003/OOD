#pragma once
#include <limits>
#include <iostream>
#include <sstream>
#include <string>
#include<cmath>

double PI = acos(-1.0);

struct Vector
{
	int x;
	int y;
};

Vector GetVectorByDirection(int direction)
{
	switch (direction)
	{
	case 0:
		return{ 1,0 };
	case 90:
		return{ 0,1 };
	case 180:
		return{ -1,0 };
	case 270:
		return{ 0,-1 };

	default:
		return {0,0};
	}
}

class DefaultStat
{
public:
	DefaultStat(std::string statName)
		:m_statName(statName) 
	{
	}
	void UpdateAndShowStats(double newStat)
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

		std::cout << "Max " << m_statName << " " << m_maxStat << std::endl;
		std::cout << "Min " << m_statName << " " << m_minStat << std::endl;
		std::cout << "Average " << m_statName << " " << (m_accStat / m_countAcc) << std::endl;

	}
private:
	std::string m_statName;
	double m_minStat = std::numeric_limits<double>::infinity();
	double m_maxStat = -std::numeric_limits<double>::infinity();
	double m_accStat = 0;
	unsigned m_countAcc = 0;
};

class WindDirectionStat
{
public:
	void UpdateAndShowStats(int direction)
	{
		Vector newVec = GetVectorByDirection(direction);
		vec.x += newVec.x;
		vec.y += newVec.y;

		double m_direction = ((int)((atan2(vec.y, vec.x)) * 180 / PI + 360)) % 360;

		if (vec.x == 0 && vec.y == 0)
		{
			std::cout << "on average, there is no wind direction\n";
		}
		else
		{
			std::cout << "Average wind direction " << m_direction << std::endl;
		}
	}
private:
	
	Vector vec{0,0};
};