#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <climits>
#include "Observer.h"
#include "Stats.h"

struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

class CDisplay: public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
		Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
		остается публичным
	*/
	void Update(SWeatherInfo const& data, std::ostringstream &os) override
	{
	
		os << "Current Temp " << data.temperature << std::endl;
		os << "Current Hum " << data.humidity << std::endl;
		os << "Current Pressure " << data.pressure << std::endl;
		os << "----------------" << std::endl;

	}
};

class CStatsDisplay : public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(SWeatherInfo const& data, std::ostringstream& os) override
	{
		temperature.UpdateAndShowStats(data.temperature, os);
		os << std::endl;
		humidity.UpdateAndShowStats(data.humidity,os);
		os << std::endl;
		pressure.UpdateAndShowStats(data.pressure, os);
		os << "----------------" << std::endl;
	}
	Temperature temperature;
	Humidity humidity;
	Pressure pressure;
};

class CWeatherData : public CObservable<SWeatherInfo>
{
public:
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

	void MeasurementsChanged(std::ostringstream& os)
	{
		NotifyObservers(os);
	}

	void SetMeasurements(double temp, double humidity, double pressure, std::ostringstream &os)
	{
		m_humidity = humidity;
		m_temperature = temp;
		m_pressure = pressure;

		MeasurementsChanged(os);
	}
protected:
	SWeatherInfo GetChangedData()const override
	{
		SWeatherInfo info;
		info.temperature = GetTemperature();
		info.humidity = GetHumidity();
		info.pressure = GetPressure();
		return info;
	}
private:
	double m_temperature = 0.0;
	double m_humidity = 0.0;	
	double m_pressure = 760.0;	
};


