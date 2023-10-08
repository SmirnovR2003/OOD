#include "WeatherData.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	CWeatherData wdIn(std::string("In"));
	CWeatherData wdOut(std::string("Out"));

	CDisplay display;
	wdIn.RegisterObserver(display);
	wdOut.RegisterObserver(display);

	CStatsDisplay statsDisplay;
	wdIn.RegisterObserver(statsDisplay);
	wdOut.RegisterObserver(statsDisplay);

	wdOut.SetMeasurements(3, 0.7, 760, 5, 0);
	wdOut.SetMeasurements(4, 0.8, 761, 5, 180);
	wdOut.SetMeasurements(4, 0.8, 761, 5, 0);
	wdOut.SetMeasurements(4, 0.8, 761, 10, 90);

	return 0;
}