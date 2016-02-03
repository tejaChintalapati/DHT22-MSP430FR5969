/*
 * mainApp.h
 *
 * Created on: Feb 01, 2016
 * Author: Teja Chintalapati
 * Contact: teja.chintalapati@gmail.com
 * Phone: +91-8792-355-512
 *
 */

#ifndef DHT22_LPM_MAINAPP_H_
#define DHT22_LPM_MAINAPP_H_

/******************************************************************************
 * INCLUDES
 */

#include <string.h>
#include <stdio.h>

#include <driverlib.h>
#include "clockInitialisation.h"
#include "DHT22.h"
#include "pinInitialisation.h"
#include "portInitialisation.h"
#include "timerInitialisation.h"
#include "WDTInitialisation.h"

#define GLOBAL_IQ    														   7			//Please read C:\ti\msp430\MSPWare_2_40_00_37\iqmathlib\MSP430-IQmathLib-UsersGuide to choose appropriate IQValue
#include "IQmathLib.h"

/******************************************************************************
 * DEFINITIONS
 */

//If true, this will give temperature in Fahrenheit. Else, you get temperature in Celsius
#define FAHRENHEIT															   false

//Used in DHT22_LPM.c
#define DHT22PORT															   GPIO_PORT_P1
#define DHT22PIN															   GPIO_PIN0

//TODO: If you are changing ports and pins, make appropriate changes in Port ISRs

//If you want to see clock frequencies, then make this true
#define DEBUG																   false

//Used in clockInitiaisation.c
#define LF_CRYSTAL_FREQUENCY_IN_HZ     										   32768
#define HF_CRYSTAL_FREQUENCY_IN_HZ											   0            // FR5969 Launchpad does not have 16MHz crystal

//Used in portInitialisation.c
#define allPins																   GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 + GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 + GPIO_PIN6 + GPIO_PIN7

/******************************************************************************
 * GLOBAL VARIABLES
 */

uint8_t hiToLowTransitionCount;
uint16_t pulseWidth;
char temperatureAndHumidityBuffer[14];

/******************************************************************************
 * FUNCTION DECLARATION
 */

void boardInitialisation(void);

#endif /* DHT22_LPM_MAINAPP_H_ */
