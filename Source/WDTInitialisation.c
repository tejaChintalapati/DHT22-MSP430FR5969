/*
 *  WDTInitialisation.c
 *
 *  Created on: Feb 02, 2016
 *  Author: Teja Chintalapati
 *	Contact: teja.chintalapati@gmail.com
 *	Phone: +91-8792-355-512
 *	Description: This file will initialise WatchDog timer. WDT wakes CPU once every 16 seconds, calculates T&H
 *
 */

/******************************************************************************
 * INCLUDES
 */

#include "mainApp.h"

/******************************************************************************
 * FUNCTION DEFINITIONS
 */

void WDTConfiguration(void)
{
	WDT_A_initIntervalTimer(WDT_A_BASE, WDT_A_CLOCKSOURCE_ACLK, WDT_A_CLOCKDIVIDER_512K);

	//Enable Watchdog Interupt
    SFR_clearInterrupt( SFR_WATCHDOG_INTERVAL_TIMER_INTERRUPT );
    SFR_enableInterrupt( SFR_WATCHDOG_INTERVAL_TIMER_INTERRUPT );
}

/******************************************************************************
 * Interrupt Service Routine
 */

#pragma vector = WDT_VECTOR
__interrupt void watchDogIsr(void)
{
	WDT_A_resetTimer(WDT_A_BASE);
	WDT_A_hold(WDT_A_BASE);
	__low_power_mode_off_on_exit();
}
