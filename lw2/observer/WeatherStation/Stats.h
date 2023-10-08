#pragma once
#include <limits>
#include <iostream>


class Temperature
{
public:
	void UpdateAndShowStats(double newStat)
	{
		if (m_minTemperature > newStat)
		{
			m_minTemperature = newStat;
		}
		if (m_maxTemperature < newStat)
		{
			m_maxTemperature = newStat;
		}
		m_accTemperature += newStat;
		++m_countAcc;

		std::cout << "Max Temp " << m_maxTemperature << std::endl;
		std::cout << "Min Temp " << m_minTemperature << std::endl;
		std::cout << "Average Temp " << (m_accTemperature / m_countAcc) << std::endl;

	}
private:
	double m_minTemperature = std::numeric_limits<double>::infinity();
	double m_maxTemperature = -std::numeric_limits<double>::infinity();
	double m_accTemperature = 0;
	unsigned m_countAcc = 0;
};

class Humidity
{
public:
	void UpdateAndShowStats(double newStat) 
	{
		if (m_minHumidity > newStat)
		{
			m_minHumidity = newStat;
		}
		if (m_maxHumidity < newStat)
		{
			m_maxHumidity = newStat;
		}
		m_accHumidity += newStat;
		++m_countAcc;

		std::cout << "Max Hum " << m_maxHumidity << std::endl;
		std::cout << "Min Hum " << m_minHumidity << std::endl;
		std::cout << "Average Hum " << (m_accHumidity / m_countAcc) << std::endl;

	}
private:
	double m_minHumidity = std::numeric_limits<double>::infinity();
	double m_maxHumidity = -std::numeric_limits<double>::infinity();
	double m_accHumidity = 0;
	unsigned m_countAcc = 0;
};

class Pressure
{
public:
	void UpdateAndShowStats(double newStat) 
	{
		if (m_minPressure > newStat)
		{
			m_minPressure = newStat;
		}
		if (m_maxPressure < newStat)
		{
			m_maxPressure = newStat;
		}
		m_accPressure += newStat;
		++m_countAcc;

		std::cout << "Max Pressure " << m_maxPressure << std::endl;
		std::cout << "Min Pressure " << m_minPressure << std::endl;
		std::cout << "Average Pressure " << (m_accPressure / m_countAcc) << std::endl;

	}
private:
	double m_minPressure = std::numeric_limits<double>::infinity();
	double m_maxPressure = -std::numeric_limits<double>::infinity();
	double m_accPressure = 0;
	unsigned m_countAcc = 0;
};

