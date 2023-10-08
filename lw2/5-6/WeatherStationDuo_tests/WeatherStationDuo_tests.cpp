// WeatherStationDuo_tests.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../WeatherStation/WeatherData.h"
#include "sstream"
#include<string>

using namespace std;

SCENARIO("WeatherStationDuo tests")
{
	SECTION("Check with any sensir type")
	{
		ostringstream os;

		CWeatherData wdIn(string("In"));
		CWeatherData wdOut(string("Out"));

		CDisplay display(os);
		wdIn.RegisterObserver(display);
		wdOut.RegisterObserver(display);

		CStatsDisplay statsDisplay(os);
		wdIn.RegisterObserver(statsDisplay);
		wdOut.RegisterObserver(statsDisplay);

		wdIn.SetMeasurements(20, 0.7, 760);
		wdOut.SetMeasurements(3, 0.7, 760);
		wdIn.SetMeasurements(25, 0.8, 770);
		wdOut.SetMeasurements(4, 0.8, 761);

		string s("Current In Temp 20\nCurrent In Hum 0.7\nCurrent In Pressure 760\n----------------\nMax In Temp 20\nMin In Temp 20\nAverage In Temp 20\n----------------\nCurrent Out Temp 3\nCurrent Out Hum 0.7\nCurrent Out Pressure 760\n----------------\nMax Out Temp 3\nMin Out Temp 3\nAverage Out Temp 3\n----------------\nCurrent In Temp 25\nCurrent In Hum 0.8\nCurrent In Pressure 770\n----------------\nMax In Temp 25\nMin In Temp 20\nAverage In Temp 22.5\n----------------\nCurrent Out Temp 4\nCurrent Out Hum 0.8\nCurrent Out Pressure 761\n----------------\nMax Out Temp 4\nMin Out Temp 3\nAverage Out Temp 3.5\n----------------\n");
		CHECK(os.str() == s);
	}
}