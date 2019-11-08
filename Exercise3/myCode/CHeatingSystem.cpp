/*
 * CHeatingSystem.cpp
 *
 *  Created on: Nov 6, 2019
 *      Author: Aadarshxp
 */

#include "CHeatingSystem.h"

CHeatingSystem::CHeatingSystem()
{
	m_heatingSystemStatus = HEATING_SYSTEM_OFF ;
}

void CHeatingSystem::powerOnHeatingSystem()
{
	m_heatingSystemStatus = HEATING_SYSTEM_ON ;
}

void CHeatingSystem::powerOffHeatingSystem()
{
	m_heatingSystemStatus = HEATING_SYSTEM_OFF ;
}

HeatingSystem_t CHeatingSystem::getStatusOfHeatingSystem()
{
	return (m_heatingSystemStatus);
}
