#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>
#include "Observer.h"
#include "Stats.h"
#include<boost/signals2/signal.hpp>
namespace signals = boost::signals2;

namespace ph = std::placeholders;

//добавить разные
struct SWeatherInfoIn
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
	std::string sensorName;
};
struct SWeatherInfoOut
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
	double windSpeed = 0.0;
	int windDirection = 0;
	std::string sensorName;
};

enum class SensorType
{
	In,
	Out,
};


class CDisplayOut 
{
public:
	void Update(SWeatherInfoOut const& data)
	{
		std::cout << "Current " << data.sensorName << " Temp " << data.temperature << std::endl;
		std::cout << "Current " << data.sensorName << " Hum " << data.humidity << std::endl;
		std::cout << "Current " << data.sensorName << " Pressure " << data.pressure << std::endl;
		std::cout << "Current wind speed " << data.windSpeed << std::endl;
		std::cout << "Current wind direction " << data.windDirection << std::endl;

		std::cout << "----------------" << std::endl;
	}
};

class CDisplayIn
{
public:
	void Update(SWeatherInfoIn const& data)
	{
		std::cout << "Current " << data.sensorName << " Temp " << data.temperature << std::endl;
		std::cout << "Current " << data.sensorName << " Hum " << data.humidity << std::endl;
		std::cout << "Current " << data.sensorName << " Pressure " << data.pressure << std::endl;

		std::cout << "----------------" << std::endl;
	}
};

class CStatsDisplayOut
{
public:
	CStatsDisplayOut()
		: m_temperatureOut()
		, m_windSpeed()
		, m_windDirection()
	{
	};
	void Update(SWeatherInfoOut const& data) 
	{

		m_temperatureOut.Update(data.temperature);
		m_windSpeed.Update(data.windSpeed);
		m_windDirection.Update(data.windDirection);

		std::cout << "Max out temp " << m_temperatureOut.GetMax() << std::endl;
		std::cout << "Min out temp " << m_temperatureOut.GetMin() << std::endl;
		std::cout << "Average out temp " << m_temperatureOut.GetAverage() << std::endl;
		std::cout << std::endl;

		std::cout << "Max wind speed " << m_windSpeed.GetMax() << std::endl;
		std::cout << "Min wind speed " << m_windSpeed.GetMin() << std::endl;
		std::cout << "Average wind speed " << m_windSpeed.GetAverage() << std::endl;
		std::cout << std::endl;

		if (m_windDirection.IsAverageDirection())
		{
			std::cout << "Average wind direction " << m_windDirection.GetAverageDirection() << std::endl;
		}
		else
		{
			std::cout << "No average wind direction\n";
		}


		std::cout << "----------------" << std::endl;
	}

private:
	DefaultStat m_temperatureOut;
	DefaultStat m_windSpeed;
	WindDirectionStat m_windDirection;
};

class CStatsDisplayIn
{
public:
	CStatsDisplayIn()
		: m_temperatureIn()
	{
	};
	void Update(SWeatherInfoIn const& data)
	{
		m_temperatureIn.Update(data.temperature);
		std::cout << "Max in temp " << m_temperatureIn.GetMax() << std::endl;
		std::cout << "Min in temp " << m_temperatureIn.GetMin() << std::endl;
		std::cout << "Average in temp " << m_temperatureIn.GetAverage() << std::endl;

		std::cout << "----------------" << std::endl;
	}

private:
	DefaultStat m_temperatureIn;
};

class CWeatherData
{
public:
	using InUpdatedSignal = signals::signal<void(SWeatherInfoIn data)>;
	using OutUpdatedSignal = signals::signal<void(SWeatherInfoOut data)>;
	using InSlot = InUpdatedSignal::slot_type;
	using OutSlot = OutUpdatedSignal::slot_type;
	CWeatherData()
	{
	}

	signals::connection RegisterObserver(const InSlot& slot, SensorType type)
	{

		return m_inObservers.connect(slot);

	}

	signals::connection RegisterObserver(const OutSlot& slot, SensorType type)
	{
		return m_outObservers.connect(slot);
	}

	void NotifyObservers(SensorType sensorType) 
	{
		if (sensorType == SensorType::In)
		{
			SWeatherInfoIn data = GetChangedInData();
			m_inObservers(data);
		}
		else
		{
			SWeatherInfoOut data = GetChangedOutData();
			m_outObservers(data);
		}
	}

	void RemoveObserver(signals::connection observer, SensorType sensorType)
	{
		if (sensorType == SensorType::In)
		{
			m_inObservers.disconnect(observer);
		}
		else
		{
			m_outObservers.disconnect(observer);
		}
	}

	// Температура в градусах Цельсия
	double GetInTemperature()const
	{
		return m_inTemperature;
	}
	// Относительная влажность (0...100)
	double GetInHumidity()const
	{
		return m_inHumidity;
	}
	// Атмосферное давление (в мм.рт.ст)
	double GetInPressure()const
	{
		return m_inPressure;
	}
	// Температура в градусах Цельсия
	double GetOutTemperature()const
	{
		return m_outTemperature;
	}
	// Относительная влажность (0...100)
	double GetOutHumidity()const
	{
		return m_outHumidity;
	}
	// Атмосферное давление (в мм.рт.ст)
	double GetOutPressure()const
	{
		return m_outPressure;
	}

	double GetWindSpeed()const
	{
		return m_windSpeed;
	}

	int GetWindDirection()const
	{
		return m_windDirection;
	}

	void SetMeasurements(double temp, double humidity, double pressure)
	{
		m_inHumidity = humidity;
		m_inTemperature = temp;
		m_inPressure = pressure;

		NotifyObservers(SensorType::In);
	}

	void SetMeasurements(double temp, double humidity, double pressure, double windSpeed, int windDirection)
	{
		m_outHumidity = humidity;
		m_outTemperature = temp;
		m_outPressure = pressure;
		m_windSpeed = windSpeed;
		m_windDirection = windDirection;

		NotifyObservers(SensorType::Out);
	}
protected:
	SWeatherInfoIn GetChangedInData()const 
	{
		SWeatherInfoIn info;

		info.temperature = GetInTemperature();
		info.humidity = GetInHumidity();
		info.pressure = GetInPressure();
		info.sensorName = "In";

		return info;
	}
	SWeatherInfoOut GetChangedOutData()const 
	{
		SWeatherInfoOut info;

		info.temperature = GetOutTemperature();
		info.humidity = GetOutHumidity();
		info.pressure = GetOutPressure();
		info.windSpeed = GetWindSpeed();
		info.windDirection = GetWindDirection();
		info.sensorName = "Out";

		return info;
	}
private:

	double m_inTemperature = 0.0;
	double m_inHumidity = 0.0;
	double m_inPressure = 760.0;
	double m_outTemperature = 0.0;
	double m_outHumidity = 0.0;
	double m_outPressure = 760.0;
	double m_windSpeed = 0.0;
	int m_windDirection = 0;

	InUpdatedSignal m_inObservers;
	OutUpdatedSignal m_outObservers;
};