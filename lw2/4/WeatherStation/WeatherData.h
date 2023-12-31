﻿#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>
#include "Observer.h"
#include "Stats.h"


struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
	std::string sensorName;
};

class CDisplay: public IObserver<SWeatherInfo>
{
public:
	CDisplay(std::ostringstream& os) :m_os(&os) {};
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
		Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
		остается публичным
	*/
	void Update(SWeatherInfo const& data) override
	{
		std::cout << "Current " << data.sensorName << " Temp " << data.temperature << std::endl;
		std::cout << "Current " << data.sensorName << " Hum " << data.humidity << std::endl;
		std::cout << "Current " << data.sensorName << " Pressure " << data.pressure << std::endl;

		*m_os << "Current " << data.sensorName << " Temp " << data.temperature << std::endl;
		*m_os << "Current " << data.sensorName << " Hum " << data.humidity << std::endl;
		*m_os << "Current " << data.sensorName << " Pressure " << data.pressure << std::endl;


		std::cout << "----------------" << std::endl;
		*m_os << "----------------" << std::endl;


	}
	std::ostringstream* m_os;
};

class CStatsDisplay : public IObserver<SWeatherInfo>
{
public:
	CStatsDisplay(std::ostringstream& os)
		: m_os(&os)
		, m_temperatureIn("In Temp", &os)
		, m_temperatureOut("Out Temp", &os)
	{
	};
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(SWeatherInfo const& data) override
	{
		if (data.sensorName == "In")
		{
			m_temperatureIn.UpdateAndShowStats(data.temperature);
		}
		else
		{
			m_temperatureOut.UpdateAndShowStats(data.temperature);
		}
		
		std::cout << "----------------" << std::endl;
		*m_os << "----------------" << std::endl;
	}

	DefaultStat m_temperatureIn;
	DefaultStat m_temperatureOut;

	std::ostringstream* m_os;
};

class CWeatherData : public CObservable<SWeatherInfo>
{
public:
	CWeatherData(std::string name)
		:CObservable(name)
	{}
	// Температура в градусах Цельсия
	double GetTemperature()const
	{
		return m_temperature;
	}
	// Относительная влажность (0...100)
	double GetHumidity()const
	{
		return m_humidity;
	}
	// Атмосферное давление (в мм.рт.ст)
	double GetPressure()const
	{
		return m_pressure;
	}

	void MeasurementsChanged()
	{
		NotifyObservers();
	}

	void SetMeasurements(double temp, double humidity, double pressure)
	{
		m_humidity = humidity;
		m_temperature = temp;
		m_pressure = pressure;

		MeasurementsChanged();
	}
protected:
	SWeatherInfo GetChangedData()const override
	{
		SWeatherInfo info;

		info.temperature = GetTemperature();
		info.humidity = GetHumidity();
		info.pressure = GetPressure();
		info.sensorName = GetSensorName();

		return info;
	}
private:
	double m_temperature = 0.0;
	double m_humidity = 0.0;
	double m_pressure = 760.0;
};
