#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>
#include "Observer.h"
#include "Stats.h"


enum class StatsType
{
	Temperature = 0,
	Humidity,
	Pressure,
	Wind
};

struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
	double windSpeed = 0.0;
	int windDirection = 0;
	std::string sensorName;
};



class CDisplay: public IObserver<StatsType,SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
		Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
		остается публичным
	*/
	void Update(StatsType type, SWeatherInfo const& data) override
	{
		switch (type)
		{
		case StatsType::Temperature:
			std::cout << "Current " << data.sensorName << " Temp " << data.temperature << std::endl;
			break;
		case StatsType::Humidity:
			std::cout << "Current " << data.sensorName << " Hum " << data.humidity << std::endl;
			break;
		case StatsType::Pressure:
			std::cout << "Current " << data.sensorName << " Pressure " << data.pressure << std::endl;
			break;
		case StatsType::Wind:
			std::cout << "Current wind speed " << data.windSpeed << std::endl;
			std::cout << "Current wind direction " << data.windDirection << std::endl;
			break;
		default:
			break;
		}

		std::cout << "----------------" << std::endl;
	};
};

class CStatsDisplay : public IObserver<StatsType,SWeatherInfo>
{
public:
	CStatsDisplay()
		: m_temperature("Temp")
		, m_humidity("Hum")
		, m_pressure("Pres")
		, m_windSpeed("wind speed")
		, m_windDirection()
	{
	};
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(StatsType type, SWeatherInfo const& data) override
	{
		switch (type)
		{
		case StatsType::Temperature:
			m_temperature.UpdateAndShowStats(data.temperature);
			break;
		case StatsType::Humidity:
			m_humidity.UpdateAndShowStats(data.humidity);
			break;
		case StatsType::Pressure:
			m_pressure.UpdateAndShowStats(data.pressure);
			break;
		case StatsType::Wind:
			m_windSpeed.UpdateAndShowStats(data.windSpeed);
			m_windDirection.UpdateAndShowStats(data.windDirection);
			break;
		default:
			break;
		}
		std::cout << "----------------" << std::endl;
	}

	DefaultStat m_temperature;
	DefaultStat m_humidity;
	DefaultStat m_pressure;
	DefaultStat m_windSpeed;
	WindDirectionStat m_windDirection;
};

class CWeatherData : public CObservable<StatsType, SWeatherInfo>
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

	double GetWindSpeed()const
	{
		return m_windSpeed;
	} 

	int GetWindDirection()const
	{
		return m_windDirection;
	}

	void MeasurementsChanged(StatsType type)
	{
		NotifyObservers(type);
	}

	void SetMeasurements(double temp, double humidity, double pressure, double windSpeed, int windDirection)
	{
		if (m_humidity != humidity) 
		{ 
			m_humidity = humidity; 
			MeasurementsChanged(StatsType::Humidity);
		};
		if (m_temperature != temp)
		{ 
			m_temperature = temp;
			MeasurementsChanged(StatsType::Temperature);
		};
		if (m_pressure != pressure)
		{ 
			m_pressure = pressure;
			MeasurementsChanged(StatsType::Pressure);
		};
		if (m_windSpeed != windSpeed || m_windDirection != windDirection)
		{
			m_windSpeed = windSpeed;
			m_windDirection = windDirection;
			MeasurementsChanged(StatsType::Wind);
		};
	}

protected:
	SWeatherInfo GetChangedData()const override
	{
		SWeatherInfo info;

		info.temperature = GetTemperature();
		info.humidity = GetHumidity();
		info.pressure = GetPressure();
		info.windSpeed = GetWindSpeed();
		info.windDirection = GetWindDirection();
		info.sensorName = GetSensorName();

		return info;
	}
private:
	double m_temperature = 0.0;
	double m_humidity = 0.0;
	double m_pressure = 760.0;
	double m_windSpeed = 0.0;
	int m_windDirection = 0;
};
