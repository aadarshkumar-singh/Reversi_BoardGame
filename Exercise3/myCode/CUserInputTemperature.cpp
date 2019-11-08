/*
 * CUserInputTemperature.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: Aadarshxp
 */

#include "CUserInputTemperature.h"

CUserInputTemperature::CUserInputTemperature(float roomTemperature)
{
	m_UserTemperature = roomTemperature ;
}

UserTemperatureErrorCode_t CUserInputTemperature::incrementTemperature()
{
	UserTemperatureErrorCode_t errorCode = INCREMENT_TEMPERATURE_SUCCESS;

	/**
	 * If user temperature is above MAXIMUM_TEMPERATURE_THRESHOLD , return MAXIMUM_TEMPERATURE_THRESHOLD_REACHED
	 * If user temperature is below MINIMUM_TEMPERATURE_THRESHOLD , return MINIMUM_TEMPERATURE_THRESHOLD_REACHED
	 * otherwise increment the user temperature by 1 and return INCREMENT_TEMPERATURE_SUCCESS
	 */

	return errorCode ;
}

UserTemperatureErrorCode_t CUserInputTemperature::decrementTemperature()
{
	UserTemperatureErrorCode_t errorCode = DECREMENT_TEMPERATURE_SUCCESS;

	/**
	 * If user temperature is above MAXIMUM_TEMPERATURE_THRESHOLD , return MAXIMUM_TEMPERATURE_THRESHOLD_REACHED
	 * If user temperature is below MINIMUM_TEMPERATURE_THRESHOLD , return MINIMUM_TEMPERATURE_THRESHOLD_REACHED
	 * otherwise decrement the user temperature by 1 and return DECREMENT_TEMPERATURE_SUCCESS
	 */

	return errorCode ;

}
float CUserInputTemperature::getUserDesiredTemperature()
{

	/**
	 * If user temperature is within specified MINIMUM_TEMPERATURE_THRESHOLD and MAXIMUM_TEMPERATURE_THRESHOLD
	 * return m_UserTemperature otherwise return DEFAULT_ROOM_TEMPERATURE
	 */

	return (m_UserTemperature);

}
