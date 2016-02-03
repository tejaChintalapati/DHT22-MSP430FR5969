/*
 * DHT22.h
 *
 * Created on: Feb 03, 2016
 * Author: Teja Chintalapati
 * Contact: teja.chintalapati@gmail.com
 * Phone: +91-8792-355-512
 *
 */

#ifndef DHT22_LPM_DHT22_H_
#define DHT22_LPM_DHT22_H_

/******************************************************************************
 * FUNCTION DECLARATIONS
 */

void triggerDHT22(void);												//Will send pulses to trigger DHT22
float getTemperature(void);												//Will return local temperature
float getHumidity(void);												//Will return local humidity
void getTemperatureAndHumidity(void);									//Changes both T&H in temperatureAndHumidityBuffer

#endif /* DHT22_LPM_DHT22_H_ */
