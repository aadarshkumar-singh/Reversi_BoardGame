// Standard (system) header files
#include <iostream>
#include <stdlib.h>

using namespace std;

#include "CTemperatureController.h"

// Main program
int main (void)
{
    // TODO: Add your program code here
	cout << "HeatController started." << endl << endl;

	CTemperatureController temperatureRegulator ;
	temperatureRegulator.startTemperatureController();

	return 0;
}
