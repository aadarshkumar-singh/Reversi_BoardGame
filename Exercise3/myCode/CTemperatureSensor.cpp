/*
 * CTemperatureSensor.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: Aadarshxp
 */

#include "CTemperatureSensor.h"

CTemperatureSensor::CTemperatureSensor()
{
	m_temperatureSensorValue = 0.0 ;
}

float CTemperatureSensor::getTemperatureValueFromSensor()
{
	return (m_temperatureSensorValue);
}

TemperatureSensorErrorCode_t CTemperatureSensor::setTemperatureValueOfSensor(float temperatureSensorValue)
{
	TemperatureSensorErrorCode_t errorCode = TEMPERATURE_SENSOR_OK ;

	/**
	 * Check the sanity of received sensor value
	 * if valid then m_temperatureSensorValue = temperatureSensorValue
	 * else assign ERROR value(TEMPERATURE_SENSOR_ERROR_VALUE) to the m_temperatureSensorValue
	 */

	return errorCode ;

}
