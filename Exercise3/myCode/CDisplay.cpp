/*
 * CDisplay.cpp
 *
 *  Created on: Nov 6, 2019
 *      Author: Aadarshxp
 */

#include <string.h>
#include "CDisplay.h"


CDisplay::CDisplay()
{
	strcpy(m_displayText,"Temperature controller");
}

void CDisplay::DisplayTemperatureData(float userTemperature)
{
	/**
	 * Display Set temperature : <userTemperature>
	 */
}

void CDisplay::DisplayTemperatureData(float userTemperature, float sensorData)
{
	/**
	 * Display Average Temperature : <sensor data>
	 * 		   Set temperature : <userTemperature>
	 */
}

void CDisplay::DisplayMessages(const char* displaytext)
{
	strcpy(m_displayText,displaytext);

	//Display the message

}
