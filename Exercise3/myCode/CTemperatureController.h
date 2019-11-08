/**
 * \file CTemperatureController.h
 * \author Aadarsh Kumar Singh
 * \date 06.11.2019
 *
 * \brief CTemperatureController.h
 * \n This file provides the APIs to control the temperature of the room as per the
 * temperature set by the user.
 *
 * \note
 *  The user can set the input temperature from MINIMUM_TEMPERATURE_THRESHOLD to
 *  MAXIMUM_TEMPERATURE_THRESHOLD,the temperature sensor can sense the temperature
 *  in the range from TEMEPERATURE_SENSOR_MINIMUM_RANGE to TEMEPERATURE_SENSOR_MAXIMUM_RANGE
 */

#ifndef CTEMPERATURECONTROLLER_H_
#define CTEMPERATURECONTROLLER_H_

#include "CUserInputTemperature.h"
#include "CButtonInput.h"
#include "CTemperatureSensor.h"
#include "CHeatingSystem.h"
#include "CButtonInput.h"
#include "CDisplay.h"
#include "CIndicatorLed.h"

/**
 * \brief
 * Defines the error code for temperature controller module
 */
enum TemperatureControllerErrorCode_e
{
	PRIMARY_SENSOR_ERROR,   	//!< primary temperature sensor fails to work
	SECONDARY_SENSOR_ERROR, 	//!< secondary temperature sensor fails to work
	MEAN_TEMPERATUE_OK,	    	//!< if average temperature sensor has valid value
	MEAN_TEMPERATURE_ERROR, 	//!< if both the sensor fails
	OFFSET_TEMPERATURE_OK,		//!< Offset temperature calculation performed
	MAINTAIN_TEMPERATURE_ERROR, //!< Error in maintaining temperature
	MAINTAIN_TEMPERATURE_OK,    //!< Temperature is maintained for the cycle
};
typedef enum TemperatureControllerErrorCode_e TemperatureControllerErrorCode_t;


/**
 * \brief
 * Defines the state of temperature controller
 */
enum TemperatureControllerState_e
{
	TEMPERATURE_CONTROLLER_ERROR, //!< Failure in maintaining the temperature
	TEMPERATURE_CONTROLLER_OK,    //!< Temperature is maintained for the cycle
};
typedef enum TemperatureControllerState_e TemperatureControllerState_t;

/**
 * \brief
 * This class provides the APIs to maintain the temperature of the room as per the user input ,
 * When the offset of user temperature and room temperature obtained from the sensor is positive,
 * Heating system will be powered on , else the Heating system will remain off.
 */
class CTemperatureController
{
	CTemperatureSensor m_primarySensorData;
	CTemperatureSensor m_secondarySensorData;
	CHeatingSystem m_heatingSystemStatusFlag ;
	CUserInputTemperature m_userTemperature;
	CButtonInput m_inputButton;
	CDisplay m_displayMessage;
	CIndicatorLed m_led;
	float m_averageTemperature;
	float m_offsetTemperature;
	TemperatureControllerState_t m_ControllerStatus ;


	/**
	 * Reads primary and secondary temperature sensor data and checks for there validity ,
	 * Then the mean temperature is calculated
	 *
	 * @return TemperatureControllerErrorCode_t MEAN_TEMPERATUE_OK : if both sensors are working
	 * 											MEAN_TEMPERATURE_ERROR : if both sensors fail
	 * 											PRIMARY_SENSOR_ERROR : if primary sensor fail
	 * 											SECONDARY_SENSOR_ERROR : if secondary sensor fail
	 */
	TemperatureControllerErrorCode_t getMeanTemperatureValue();

	/**
	 * Calculates the temperature offset between the current Temperature(from sensor)
	 * and user specified temperature.
	 *
	 * @return TemperatureControllerErrorCode_t OFFSET_TEMPERATURE_OK : if offset temperature is calculated
	 * 											MEAN_TEMPERATURE_ERROR : if calculation of offset fails
	 */
	TemperatureControllerErrorCode_t calculateTemperatureOffset();

public:

	/**
	 * Initializes the instance average temperature , offset and controller status with given values
	 */
	CTemperatureController();

	/**
	 * Continously checks :
	 * \n the button flag to find the button pressed,
	 *    based on the button pressed temperature is either incremented/decremented
	 *    or remains set to default room temp.
	 * \n the heating system status flag to check if it is set to on or not,
	 *    if set turns the heating system on or it is off, indicated by Green Led.
	 */
	void startTemperatureController();

	/**
	 * This API is triggered on Timer Interrupt after every 5 mins.
	 * If the calculated temperature offset is positive , Heating system flag is set to power on
	 * otherwise heating system is set to off.	 *
	 * It also displays the room temperature and temperature set by user on Display.
	 * if temperature controller fails to maintain temperature RED LED is on , otherwise its off.
	 */
	void maintainTemperatureSetbyUser();

};

#endif /* CTEMPERATURECONTROLLER_H_ */
