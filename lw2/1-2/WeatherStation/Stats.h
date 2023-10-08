#pragma once
#include <limits>
#include <iostream>
#include <string>


class Stat
{
public:
	Stat(std::string statName)
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