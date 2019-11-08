/*
 * CIndicatorLed.cpp
 *
 *  Created on: Nov 8, 2019
 *      Author: Aadarshxp
 */

#include "CIndicatorLed.h"

CIndicatorLed::CIndicatorLed()
{
	m_LedType = NO_LED;
}

Led_ErrCode_t CIndicatorLed::ledSwitchOn(Led_Types_t ledType)
{
	Led_ErrCode_t errorCode = LED_OK ;
	/*
	 * Use switch case to find the type of led passed as parameter
	 * and turn on the led , by making the respective I/O pin high.
	 * In invalid type return LED_ERROR
	 */
	return errorCode;
}

Led_ErrCode_t CIndicatorLed::ledSwitchOff(Led_Types_t ledType)
{
	Led_ErrCode_t errorCode = LED_OK ;

	/*
	 * Use switch case to find the type of led passed as parameter
	 * and turn off the led , by making the respective I/O pin zero.
	 * In invalid type return LED_ERROR
	 */

	return errorCode;
}
