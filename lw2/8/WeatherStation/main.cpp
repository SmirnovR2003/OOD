#include "WeatherData.h"
#include "Observer.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	CWeatherData wd;

	CDisplayIn displayIn;
	CDisplayOut displayOut;
	wd.RegisterObserver((CWeatherData::InSlot)bind(&CDisplayIn::Update, &displayIn, ph::_1), SensorType::In);
	wd.RegisterObserver((CWeatherData::OutSlot)bind(&CDisplayOut::Update, &displayOut, ph::_1), SensorType::Out);

	CStatsDisplayIn statsDisplayIn;
	CStatsDisplayOut statsDisplayOut;
	wd.RegisterObserver((CWeatherData::InSlot)bind(&CStatsDisplayIn::Update, &statsDisplayIn, ph::_1), SensorType::In);
	wd.RegisterObserver((CWeatherData::OutSlot)bind(&CStatsDisplayOut::Update, &statsDisplayOut, ph::_1), SensorType::Out);

	wd.SetMeasurements(3, 0.7, 760, 5, 0);
	wd.SetMeasurements(4, 0.8, 761);
	wd.SetMeasurements(4, 0.8, 761, 5, 270);
	wd.SetMeasurements(4, 0.8, 761);

	return 0;
}