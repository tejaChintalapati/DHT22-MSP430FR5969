/*
 * 	pinInitialisation.c
 *
 *  Created on: Feb 03, 2016
 *  Author: Teja Chintalapati
 *	Contact: teja.chintalapati@gmail.com
 *	Phone: +91-8792-355-512
 *	Description: This file will initialise all pins required in this program
 *
 */

/******************************************************************************
 * INCLUDES
 */

#include "mainApp.h"

/******************************************************************************
 * FUNCTION DEFINITIONS
 */

void pinConfiguration(void)
{
    /*
     * Set LFXT clock pins to crystal input. By default, they're configured as GPIO.
     * If you don't configure these pins, your code will be stuck in CS_turnOnLFXT function
     */
    GPIO_setAsPeripheralModuleFunctionInputPin( GPIO_PORT_PJ, GPIO_PIN4 + GPIO_PIN5, GPIO_PRIMARY_MODULE_FUNCTION );
}


/*
 * Pin ISR
 */

#pragma vector = PORT1_VECTOR;
__interrupt void Port1_ISR(void)
{
	switch(__even_in_range(P1IV, 0x10))
	{
	case P1IV_NONE : break;							//No Interrupt pending
	case P1IV_P1IFG0 :
		if(P1IES & DHT22PIN)						//High to low transition
		{
			hiToLowTransitionCount++;
			GPIO_selectInterruptEdge(DHT22PORT, DHT22PIN, GPIO_LOW_TO_HIGH_TRANSITION);
			Timer_B_stop(TIMER_B0_BASE);
			//Do some processing (Calculating T&H)
			__low_power_mode_off_on_exit();
		}
		else										//Low to high transition
		{
			GPIO_selectInterruptEdge(DHT22PORT, DHT22PIN, GPIO_HIGH_TO_LOW_TRANSITION);
			//To calculate pulseWidth(>30uS = 1 else, 0)
			Timer_B_startCounter(TIMER_B0_BASE, TIMER_B_UP_MODE);
		}
		break;						//(0x02) P1.0 interrupt
	case P1IV_P1IFG1 : break;						//(0x04) P1.1 interrupt
	case P1IV_P1IFG2 : break;						//(0x06) P1.2 interrupt
	case P1IV_P1IFG3 : break;						//(0x08) P1.3 interrupt
	case P1IV_P1IFG4 : break;						//(0x0A) P1.4 interrupt
	case P1IV_P1IFG5 : break;						//(0x0C) P1.5 interrupt
	case P1IV_P1IFG6 : break;						//(0x0E) P1.6 interrupt
	case P1IV_P1IFG7 : 								//(0x10) P1.7 interrupt
		break;
	default :
		__never_executed();
		break;
	}
}
