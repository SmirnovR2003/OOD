#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>
#include "Observer.h"
#include "Stats.h"

namespace ph = std::placeholders;

struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
	double windSpeed = 0.0;
	int windDirection = 0;
	std::string sensorName;
	CObservable<SWeatherInfo>* sensor;
};

class CWeatherData : public CObservable<SWeatherInfo>
{
public:
	CWeatherData(std::string name)
		:m_name(name)
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

	void MeasurementsChanged()
	{
		NotifyObservers();
	}

	void SetMeasurements(double temp, double humidity, double pressure, double windSpeed, int windDirection)
	{
		m_humidity = humidity;
		m_temperature = temp;
		m_pressure = pressure;
		m_windSpeed = windSpeed;
		m_windDirection = windDirection;

		MeasurementsChanged();
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
		info.sensorName = m_name;

		return info;
	}
private:
	double m_temperature = 0.0;
	double m_humidity = 0.0;
	double m_pressure = 760.0;
	double m_windSpeed = 0.0;
	int m_windDirection = 0;
	std::string m_name;
};


class CDisplay: public IObserver<SWeatherInfo>
{
public:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
		Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
		остается публичным
	*/
	void AddObservable(CObservable<SWeatherInfo>* const observable)override
	{
		m_sensors.push_back(observable);
	}
	void Update(SWeatherInfo const& data) override
	{
		std::cout << "Current " << data.sensorName << " Temp " << data.temperature << std::endl;
		std::cout << "Current " << data.sensorName << " Hum " << data.humidity << std::endl;
		std::cout << "Current " << data.sensorName << " Pressure " << data.pressure << std::endl;

		if (data.sensor == m_sensors[1])
		{
			std::cout << "Current wind speed " << data.windSpeed << std::endl;
			std::cout << "Current wind direction " << data.windDirection << std::endl;
		}

		std::cout << "----------------" << std::endl;
	}
private:
	std::vector<CObservable<SWeatherInfo>*> m_sensors;
};

class CStatsDisplay : public IObserver<SWeatherInfo>
{
public:
	CStatsDisplay()
		: m_temperatureIn("In Temp")
		, m_temperatureOut("Out Temp")
		, m_windSpeed("wind speed")
		, m_windDirection()
	{
	};
private:

	void AddObservable(CObservable<SWeatherInfo>* const observable)override
	{
		m_sensors.push_back(observable);
	}
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(SWeatherInfo const& data) override
	{
		if (data.sensor == m_sensors[0])
		{
			m_temperatureIn.Update(data.temperature);

			std::cout << "Max in temp " << m_temperatureIn.GetMax() << std::endl;
			std::cout << "Min in temp " << m_temperatureIn.GetMin() << std::endl;
			std::cout << "Average in temp " << m_temperatureIn.GetAverage() << std::endl;
		}
		else
		{
			m_temperatureOut.Update(data.temperature);
			m_windSpeed.Update(data.windSpeed);
			m_windDirection.Update(data.windDirection);

			std::cout << "Max in temp " << m_temperatureOut.GetMax() << std::endl;
			std::cout << "Min in temp " << m_temperatureOut.GetMin() << std::endl;
			std::cout << "Average in temp " << m_temperatureOut.GetAverage() << std::endl;
			std::cout << std::endl;

			std::cout << "Max in wind speed " << m_windSpeed.GetMax() << std::endl;
			std::cout << "Min in wind speed " << m_windSpeed.GetMin() << std::endl;
			std::cout << "Average in wind speed " << m_windSpeed.GetAverage() << std::endl;
			std::cout << std::endl;

			std::cout << "Average wind direction " << m_windDirection.GetAverageDirection() << std::endl;
		}
		
		std::cout << "----------------" << std::endl;
	}

private:
	std::vector<CObservable<SWeatherInfo>*> m_sensors;
	DefaultStat m_temperatureIn;
	DefaultStat m_temperatureOut;
	DefaultStat m_windSpeed;
	WindDirectionStat m_windDirection;
};