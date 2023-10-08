#include "WeatherData.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


int main()
{
	CWeatherData wdIn(std::string("In"));
	CWeatherData wdOut(std::string("Out"));

	std::ostringstream os;

	CDisplay display(os);
	wdIn.RegisterObserver(display);
	wdOut.RegisterObserver(display);

	CStatsDisplay statsDisplay(os);
	wdIn.RegisterObserver(statsDisplay);
	wdOut.RegisterObserver(statsDisplay);

	wdOut.SetMeasurements(3, 0.7, 760, 5, 90);
	wdOut.SetMeasurements(4, 0.8, 761, 5, 270);
	wdOut.SetMeasurements(4, 0.8, 761, 5, 180);
	wdOut.SetMeasurements(4, 0.8, 761, 10, 90);

	return 0;
}