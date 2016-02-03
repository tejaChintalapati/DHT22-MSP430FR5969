/*
 *  DHT22_LPM.c
 *	Created on: Feb 01, 2016
 *  Author: Teja Chintalapati
 *	Contact: teja.chintalapati@gmail.com
 *	Phone: +91-8792-355-512
 *	Description: This program will read Temperature and Humidity from DHT22
 *	Modules used: Hardware Multiplier, TimerA, TimerB
 *
 *             MSP430FR5969
 *          -----------------
 *         |              XIN|-
 *         |                 |
 *         |             XOUT|-
 *         |                 |
 *    	   |             P1.0|<--> DHT22
 *
 */

/******************************************************************************
 * INCLUDES
 */

#include "mainApp.h"

/******************************************************************************
 * MAIN
 */

void main(void)
{
	boardInitialisation();

	while(1)
	{
		getTemperatureAndHumidity();
		__low_power_mode_3();
	}
}
