#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../WeatherStation/WeatherData.h"
#include "sstream"

using namespace std;

SCENARIO("Update and delete observer")
{
	CWeatherData wd;

	CStatsDisplay statsDisplay;
	wd.RegisterObserver(statsDisplay);
	CDisplay display1(wd);
	CDisplay display2(wd);
	CDisplay display3(wd);
	wd.RegisterObserver(display1);
	wd.RegisterObserver(display2);
	wd.RegisterObserver(display3);
	CHECK_NOTHROW(wd.SetMeasurements(31.5, 0.7, 760));
	CHECK_NOTHROW(wd.SetMeasurements(31.5, 0.7, 760));
}