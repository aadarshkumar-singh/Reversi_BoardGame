/**
* \file CHeatingSystem.h
* \author Aadarsh Kumar Singh
* \date 06.11.2019
*
* \brief CHeatingSystem.h
* \n This file provides the APIs to switch on/off the heating system.
*/

#ifndef CHEATINGSYSTEM_H_
#define CHEATINGSYSTEM_H_

/**
 * \brief
 * Defines the states of heating system
 */
enum HeatingSystem_e
{
	HEATING_SYSTEM_OFF,
	HEATING_SYSTEM_ON,
};
typedef HeatingSystem_e HeatingSystem_t ;


/**
 * \brief
 * Provides the APIs to switch on/off the heating system
 * Represents the flag m_heatingSystemStatus of type HeatingSystem_t
 */
class CHeatingSystem
{
	HeatingSystem_t m_heatingSystemStatus ;

public:
	/**
	 * Initializes the instance power status with HEATING_SYSTEM_OFF
	 */
	CHeatingSystem();
	/**
	 * Sets the Flag to switch on the heating system
	 */
	void powerOnHeatingSystem();
	/**
	 * Sets the Flag to switch off the heating system
	 */
	void powerOffHeatingSystem();
	/**
	 * Returns the flag which represents the power status of Heating System
	 * @return HeatingSystem_t : HEATING_SYSTEM_OFF , if the status of heating system is off.
	 * 							 HEATING_SYSTEM_ON  , if the status of the heating system is on.
	 */
	HeatingSystem_t getStatusOfHeatingSystem();



};

#endif /* CHEATINGSYSTEM_H_ */
