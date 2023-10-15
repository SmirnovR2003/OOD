#include "WeatherData.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


int main()
{
	CWeatherData wdOut(std::string("Out"));

	CDisplay display;
	wdOut.RegisterObserver(StatsType::Wind, display);

	CStatsDisplay statsDisplay;
	wdOut.RegisterObserver(StatsType::Wind, statsDisplay);

	wdOut.SetMeasurements(3, 0.7, 760, 5, 90);
	wdOut.SetMeasurements(4, 0.8, 761, 5, 180);
	wdOut.SetMeasurements(4, 0.8, 761, 5, 270);
	wdOut.SetMeasurements(4, 0.8, 761, 10, 0);

	return 0;
}