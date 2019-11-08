/**
 * \file CTemperatureSensor.h
 * \author Aadarsh Kumar Singh
 * \date 06.11.2019
 *
 * \brief CTemperatureSensor.h
 * \n Provides APIs to read the temperature value in celsius from the temperature sensor
 * Also set the sensor value to its data member , if values are valid
 *
 */


#ifndef CTEMPERATURESENSOR_H_
#define CTEMPERATURESENSOR_H_

/**
 * \brief Minimum range of temperature sensor in celsius
 */
#define TEMPERATURE_SENSOR_MINIMUM_RANGE -10.0
/**
 * \brief Maximum range of temperature sensor in celsius
 */
#define TEMEPERATURE_SENSOR_MAXIMUM_RANGE 40.0

/**
 * \brief Temperature value in celsius if temperature sensor has error
 */

#define TEMPERATURE_SENSOR_ERROR_VALUE 50.0

/**
* \brief
* Defines the error code for temperature data
*/
enum TemperatureSensorErrorCode_e
{
	TEMPERATURE_SENSOR_ERROR, 	//!< Error code if temperature values from sensor is not in the range TEMPERATURE_SENSOR_MINIMUM_RANGE and TEMEPERATURE_SENSOR_MAXIMUM_RANGE
	TEMPERATURE_SENSOR_OK,		//!< Error code if temperature values is in range TEMPERATURE_SENSOR_MINIMUM_RANGE and TEMEPERATURE_SENSOR_MAXIMUM_RANGE
};
typedef enum TemperatureSensorErrorCode_e TemperatureSensorErrorCode_t;

/**
 * \brief
 * Provides the APIs to read the temperature sensor values and set the
 * temperature value to the property m_temperatureSensorValue is of type float
 * if values are valid
 */
class CTemperatureSensor
{
	float m_temperatureSensorValue;

public:
	/**
	 * Initializes the instance with 0.0 degree celsius
	 */
	CTemperatureSensor();

	/**
	 * Reads the temperature value from the sensor
	 *
	 * @return m_temperatureSensorValue : temperature value from the sensor
	 */
	float getTemperatureValueFromSensor();

	/**
	 * Sets the temperature sensor value after checking its validity.
	 * The temperature sensor hardware calls this APIs every time it samples temperature values.
	 * It is assumed that it samples with frequency of every 2 mins.
	 *
	 * @param  temperatureSensorValues : Sensor Value from the temperature sensor
	 * @return TemperatureSensorErrorCode_t TEMPERATURE_SENSOR_OK :  received sensor value is within the supported range of temperature sensor
	 * 										TEMPERATURE_SENSOR_ERROR : received sensor value is not in supported range of temperature sensor
	 */
	TemperatureSensorErrorCode_t setTemperatureValueOfSensor(float temperatureSensorValues);

};

#endif /* CTEMPERATURESENSOR_H_ */
