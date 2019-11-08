/**
* \file CUserInputTemperature.h
* \author Aadarsh Kumar Singh
* \date 06.11.2019
*
* \brief CUserInputTemperature.h
* \n This file provides the APIs to increment/decrement the temperature value by 1
*    within the range of MINIMUM_TEMPERATURE_THRESHOLD to MAXIMUM_TEMPERATURE_THRESHOLD degree celsius
*    Also to read the temperature input specified by the user.
*/

#ifndef CUSERINPUTTEMPERATURE_H_
#define CUSERINPUTTEMPERATURE_H_

/**
 * \brief Maximum threshold value of the temperature that can be set/adjusted in celsius
 */
#define MAXIMUM_TEMPERATURE_THRESHOLD 30.0

/**
 * \brief Minimum threshold value of the temperature that can be set/adjusted in celsius
 */
#define MINIMUM_TEMPERATURE_THRESHOLD 18.0

/**
 * \brief default room temperature in celsius
 */
#define DEFAULT_ROOM_TEMPERATURE 25.0

/**
* \brief
* Defines the error code for increasing / decreasing temperature value is possible or not
*/
enum UserTemperatureErrorCode_e
{
	MAXIMUM_TEMPERATURE_THRESHOLD_REACHED, 	//!< Error code if tried to increment the temperature above the MAXIMUM_TEMPERATURE_THRESHOLD
	MINIMUM_TEMPERATURE_THRESHOLD_REACHED, 	//!< Error code if tried to decrement the temperature below the MINIMUM_TEMPERATURE_THRESHOLD
	INCREMENT_TEMPERATURE_SUCCESS,  		//!< Error code if incrementing by 1 is possible within the range between MINIMUM_TEMPERATURE_THRESHOLD to MAXIMUM_TEMPERATURE_THRESHOLD
	DECREMENT_TEMPERATURE_SUCCESS,          //!< Error code if decrementing by 1 is possible within the range between MINIMUM_TEMPERATURE_THRESHOLD to MAXIMUM_TEMPERATURE_THRESHOLD
};
typedef enum UserTemperatureErrorCode_e UserTemperatureErrorCode_t;

/**
 * \brief
 * Provides APIs to adjust/read the temperature specified by the user.
 * The m_UserTemperature property is of type float
 */
class CUserInputTemperature
{
	float m_UserTemperature;

public:

	/**
	 * Initializes the instance with the given room temperature
	 *
	 * @param roomTemp : Initial value for the user temperature , by default set to DEFAULT_ROOM_TEMPERATURE.
	 */
	CUserInputTemperature(float roomTemperature = DEFAULT_ROOM_TEMPERATURE);

	/**
	 * Increments the temperature value by 1
	 * if the temperature value is in the range MINIMUM_TEMPERATURE_THRESHOLD to MAXIMUM_TEMPERATURE_THRESHOLD
	 *
	 * @return  MAXIMUM_TEMPERATURE_THRESHOLD_REACHED : if user temperature > MAXIMUM_TEMPERATURE_THRESHOLD
	 *  		MINIMUM_TEMPERATURE_THRESHOLD_REACHED : if user temperature < MINIMUM_TEMPERATURE_THRESHOLD
	 *  		INCREMENT_TEMPERATURE_SUCCESS 		  : if user temperature is successfully increased by 1
	 */
	UserTemperatureErrorCode_t incrementTemperature();

	/**
	 * Decrements the temperature value by 1
	 * if the temperature value is in the range MINIMUM_TEMPERATURE_THRESHOLD to MAXIMUM_TEMPERATURE_THRESHOLD
	 *
	 * @return  MAXIMUM_TEMPERATURE_THRESHOLD_REACHED : if user temperature > MAXIMUM_TEMPERATURE_THRESHOLD
	 *  		MINIMUM_TEMPERATURE_THRESHOLD_REACHED : if user temperature < MINIMUM_TEMPERATURE_THRESHOLD
	 *  		DECREMENT_TEMPERATURE_SUCCESS 		  : if user temperature is successfully decremented  by 1
	 */
	UserTemperatureErrorCode_t decrementTemperature();

	/**
	 * Returns the temperature(input) which needs to be attained
	 *
	 * @return m_UserTemperature 		: if temperature is within MINIMUM_TEMPERATURE_THRESHOLD-MAXIMUM_TEMPERATURE_THRESHOLD
	 * 		   DEFAULT_ROOM_TEMPERATURE : if temperature is out of specified range
	 */
	float getUserDesiredTemperature();

};

#endif /* CUSERINPUTTEMPERATURE_H_ */
