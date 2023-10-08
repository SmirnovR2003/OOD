﻿// WeatherStation_Priority_tests.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../WeatherStation/Observer.h"
#include "../WeatherStation/WeatherData.h"
#include<sstream>

using namespace std;

SCENARIO("Priority  tests")
{
	SECTION("Check with equal priority")
	{
		CWeatherData wd;

		CDisplay display;
		wd.RegisterObserver(display, 1);

		CStatsDisplay statsDisplay;
		wd.RegisterObserver(statsDisplay, 1);

		wd.SetMeasurements(3, 0.7, 760);
		string s("Max Temp 3\nMin Temp 3\nAverage Temp 3\n\nMax Hum 0.7\nMin Hum 0.7\nAverage Hum 0.7\n\nMax Pressure 760\nMin Pressure 760\nAverage Pressure 760\n----------------\nCurrent Temp 3\nCurrent Hum 0.7\nCurrent Pressure 760\n----------------\n");
	}

	SECTION("Check with declared variable")
	{

	}
}
