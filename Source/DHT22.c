/*
 * 	DHT22.c
 *
 *  Created on: Feb 03, 2016
 *  Author: Teja Chintalapati
 *	Contact: teja.chintalapati@gmail.com
 *	Phone: +91-8792-355-512
 *	Description: Code for triggering DHT22 and calculating temperature and humidity
 *
 */

/******************************************************************************
 * INCLUDES
 */

#include "mainApp.h"

/******************************************************************************
 * FUNCTION DEFINITIONS
 */

void triggerDHT22(void)
{
	/*
	 * To trigger DHT22, yoy've to send 1mS low pulse followed by 20-40uS High Pulse.
	 */
	GPIO_setAsOutputPin(DHT22PORT, DHT22PIN);
	GPIO_setOutputLowOnPin(DHT22PORT, DHT22PIN);
	Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);
	__low_power_mode_3();
	GPIO_setOutputHighOnPin(DHT22PORT, DHT22PIN);
	Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);
	__low_power_mode_3();
	Timer_A_stop(TIMER_A0_BASE);
	GPIO_setAsInputPinWithPullDownResistor(DHT22PORT, DHT22PIN);
	GPIO_selectInterruptEdge(DHT22PORT, DHT22PIN, GPIO_HIGH_TO_LOW_TRANSITION);
	GPIO_clearInterrupt(DHT22PORT, allPins);
	GPIO_enableInterrupt(DHT22PORT, DHT22PIN);

	//First two pulses are Sensor Responses. We're not interested in them.
	while(hiToLowTransitionCount < 1)
		__low_power_mode_4();
	hiToLowTransitionCount = 0;
}

//float getTemperature(void)
//{
//	triggerDHT22();
//
//	int16_t temperature = 0;
//
//	while(hiToLowTransitionCount < 41)
//	{
//		__low_power_mode_4();
//
//		/*
//		 * First three bits we're receiving are junk. So, I'm considering from 3rd bit
//		 * According to datasheet, first 16 bits represent Humidity and next 16 bits represent Temperature.
//		 * 16+3(Junk) = 19
//		 */
////		if((hiToLowTransitionCount > 2) && (hiToLowTransitionCount < 19))
////		{
////			/*
////			 * TImerB will tick every 10uS. So, 5 corresponds to 50uS. If pulse is > 30uS,
////			 * then, according to DHT22 datasheet, it is 1. Else, it is 0
////			 */
////
////			if(pulseWidth > 5)
////				humidity |= 1 << (18 - hiToLowTransitionCount);
////		}
////		else if((hiToLowTransitionCount > 19) && (hiToLowTransitionCount < 35))
////		{
////			/*
////			 * TimerB will tick every 10uS. So, 5 corresponds to 50uS. If pulse is > 30uS,
////			 * then, according to DHT22 datasheet, it is 1. Else, it is 0
////			 */
////
////			if(pulseWidth > 5)
////				temperature |= 1 << (34 - hiToLowTransitionCount);
////		}
//		 if((hiToLowTransitionCount > 19) && (hiToLowTransitionCount < 35))
//		 {
//			 /*
//			  * TimerB will tick every 10uS. So, 5 corresponds to 50uS. If pulse is > 30uS,
//			  * then, according to DHT22 datasheet, it is 1. Else, it is 0
//			  */
//
//			 if(pulseWidth > 5)
//				 temperature |= 1 << (34 - hiToLowTransitionCount);
//		 }
//		pulseWidth = 0;
//	}
//
//	float temperature_IQ = _IQ7toF(_IQ7div(_IQ7(temperature), _IQ7(10)));
//
//	Timer_B_stop(TIMER_B0_BASE);
//	hiToLowTransitionCount = 0;
////	humidity = 0;
////	temperature = 0;
//	return temperature_IQ;
//}
//
//float getHumidity(void)
//{
//	triggerDHT22();
//
//	int16_t humidity = 0;
////	float humidity_IQ = 0;s
//
//	while(hiToLowTransitionCount < 41)
//	{
//		__low_power_mode_4();
//
//		/*
//		 * First three bits we're receiving are junk. So, I'm considering from 3rd bit
//		 * According to datasheet, first 16 bits represent Humidity and next 16 bits represent Temperature.
//		 * 16+3(Junk) = 19
//		 */
////		if((hiToLowTransitionCount > 2) && (hiToLowTransitionCount < 19))
////		{
////			/*
////			 * TImerB will tick every 10uS. So, 5 corresponds to 50uS. If pulse is > 30uS,
////			 * then, according to DHT22 datasheet, it is 1. Else, it is 0
////			 */
////
////			if(pulseWidth > 5)
////				humidity |= 1 << (18 - hiToLowTransitionCount);
////		}
////		else if((hiToLowTransitionCount > 19) && (hiToLowTransitionCount < 35))
////		{
////			/*
////			 * TimerB will tick every 10uS. So, 5 corresponds to 50uS. If pulse is > 30uS,
////			 * then, according to DHT22 datasheet, it is 1. Else, it is 0
////			 */
////
////			if(pulseWidth > 5)
////				temperature |= 1 << (34 - hiToLowTransitionCount);
////		}
//		if((hiToLowTransitionCount > 2) && (hiToLowTransitionCount < 19))
//		{
//			/*
//			 * TImerB will tick every 10uS. So, 5 corresponds to 50uS. If pulse is > 30uS,
//			 * then, according to DHT22 datasheet, it is 1. Else, it is 0
//			 */
//
//			if(pulseWidth > 5)
//				humidity |= 1 << (18 - hiToLowTransitionCount);
//		}
//		pulseWidth = 0;
//	}
//
//	float humidity_IQ = _IQ7toF(_IQ7div(_IQ7(humidity), _IQ7(10)));
//
//	Timer_B_stop(TIMER_B0_BASE);
//	hiToLowTransitionCount = 0;
////	humidity = 0;
////	temperature = 0;
//	return humidity_IQ;
//}

void getTemperatureAndHumidity(void)
{
	triggerDHT22();

	int16_t temperature =0, humidity = 0;

	while(hiToLowTransitionCount < 41)
	{
		__low_power_mode_4();

		/*
		 * First three bits we're receiving are junk. So, I'm considering from 3rd bit
		 * According to datasheet, first 16 bits represent Humidity and next 16 bits represent Temperature.
		 * 16+3(Junk) = 19
		 */
		if((hiToLowTransitionCount > 2) && (hiToLowTransitionCount < 19))
		{
			/*
			 * TimerB will tick every 10uS. So, 5 corresponds to 50uS. If pulse is > 30uS,
			 * then, according to DHT22 datasheet, it is 1. Else, it is 0
			 */

			if(pulseWidth > 5)
				humidity |= 1 << (18 - hiToLowTransitionCount);
		}
		else if((hiToLowTransitionCount > 19) && (hiToLowTransitionCount < 35))
		{
			/*
			 * TimerB will tick every 10uS. So, 5 corresponds to 50uS. If pulse is > 30uS,
			 * then, according to DHT22 datasheet, it is 1. Else, it is 0
			 */

			if(pulseWidth > 5)
				temperature |= 1 << (34 - hiToLowTransitionCount);
		}

		pulseWidth = 0;
	}

	float temperature_IQ = _IQ7toF(_IQ7div(_IQ7(temperature), _IQ7(10)));
	float humidity_IQ = _IQ7toF(_IQ7div(_IQ7(humidity), _IQ7(10)));

#if FAHRENHEIT
	temperature_IQ = _IQ7toF(_IQ7mpy(_IQ7(temperature_IQ), _IQ7(1.8)) + _IQ7(32));
#endif
	/*
	 * sprintf not working? Please refer to discussions at
	 * https://e2e.ti.com/support/microcontrollers/msp430/f/166/t/485180
	 */
	sprintf(temperatureAndHumidityBuffer, "%0.2f", temperature_IQ);
	strcat(temperatureAndHumidityBuffer, ",");
	sprintf(&temperatureAndHumidityBuffer[strlen(temperatureAndHumidityBuffer)], "%0.2f", humidity_IQ);
	strcat(temperatureAndHumidityBuffer, ",");

	Timer_B_stop(TIMER_B0_BASE);
	hiToLowTransitionCount = 0;
	//WDT will wake the MCU up from LPM3 once every 16 seconds
	WDT_A_start(WDT_A_BASE);
}
