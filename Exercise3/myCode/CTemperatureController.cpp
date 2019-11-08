/*
 * CTemperatureController.cpp
 *
 *  Created on: Nov 6, 2019
 *      Author: Aadarshxp
 */

#include <string.h>
#include "CTemperatureController.h"

CTemperatureController::CTemperatureController()
{
	m_averageTemperature = 0.0;
	m_offsetTemperature = DEFAULT_ROOM_TEMPERATURE ;
	m_ControllerStatus = TEMPERATURE_CONTROLLER_OK ;
}

void CTemperatureController::startTemperatureController()
{
	while(1)
	{
		/**
		 * if any button is pressed by the user , As per the button  pressed the temperature is
		 * incremented/decremented and the button flag is updated to NO_BUTTON pressed.
		 */
		// Example INCREMENT BUTTON case
		switch(m_inputButton.getButtonPressedByUser())
		{

		case INCREMENT_BUTTON :
			if (m_userTemperature.incrementTemperature() != INCREMENT_TEMPERATURE_SUCCESS)
			{
				m_displayMessage.DisplayMessages("Default temperature set");
			}
			else
			{
				m_displayMessage.DisplayTemperatureData(m_userTemperature.getUserDesiredTemperature());
			}

			m_inputButton.setButtonPressedByUser(NO_BUTTON);
			break;
		case DECREMENT_BUTTON :
			// Likewise
			break;

		case NO_BUTTON :
			// Likewise
			break;


		}

		/**
		 * Check the heating system power status if flag set to on
		 * Then trigger the heating system hardware otherwise
		 * switch it off
		 */
		if (m_heatingSystemStatusFlag.getStatusOfHeatingSystem() == HEATING_SYSTEM_ON)
		{
			m_led.ledSwitchOn(LED_GREEN);
		}
		else
		{
			m_led.ledSwitchOff(LED_GREEN);
		}

	}

}


TemperatureControllerErrorCode_t CTemperatureController::getMeanTemperatureValue()
{
	TemperatureControllerErrorCode_t errorCode = MEAN_TEMPERATUE_OK;

	float primaryTemperature = m_primarySensorData.getTemperatureValueFromSensor();
	float secondaryTemperature =m_secondarySensorData.getTemperatureValueFromSensor();


	/**
	 * Check if primary and secondary Temperature values are not equal to
	 * error value TEMPERATURE_SENSOR_ERROR_VALUE ,if so calculate mean of the temperature
	 * values using both the data otherwise use only the valid data
	 */
	// Ideal case , when both are working
	m_averageTemperature = ((primaryTemperature + secondaryTemperature)/2 );

	// Only if secondary sensor is working
	m_averageTemperature = secondaryTemperature ;

	return errorCode ;
}


TemperatureControllerErrorCode_t CTemperatureController::calculateTemperatureOffset()
{
	TemperatureControllerErrorCode_t errorCode = getMeanTemperatureValue(); ;

	if (errorCode != MEAN_TEMPERATURE_ERROR)
	{
		/**
		 * Calculates the temperature offset between the current Temperature(from sensor)
		 * and user specified temperature.
		 */
		m_offsetTemperature = m_userTemperature.getUserDesiredTemperature() - m_averageTemperature;

		errorCode = OFFSET_TEMPERATURE_OK;
	}

	return errorCode ;
}

void CTemperatureController::maintainTemperatureSetbyUser()
{
	TemperatureControllerErrorCode_t errorCode = calculateTemperatureOffset();

	if (errorCode == OFFSET_TEMPERATURE_OK )
	{
		/**
		 * If temperature offset is positive implies room temperature is less than temperature set
		 * by user , hence set the heating system flag on else heating system is off.
		 */
		if (m_offsetTemperature > 0)
			m_heatingSystemStatusFlag.powerOnHeatingSystem();
		else
			m_heatingSystemStatusFlag.powerOffHeatingSystem();

		m_ControllerStatus = TEMPERATURE_CONTROLLER_OK;
		m_led.ledSwitchOff(LED_RED);
	}
	else
	{
		m_ControllerStatus = TEMPERATURE_CONTROLLER_ERROR ;
		m_displayMessage.DisplayMessages("TEMPERATURE CONTROLLER NOT WORKING");
		m_led.ledSwitchOn(LED_RED);
	}

	m_displayMessage.DisplayTemperatureData(m_userTemperature.getUserDesiredTemperature(), m_averageTemperature);
}
