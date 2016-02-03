# DHT22-MSP430FR5969
Interfacing DHT22 with MSP430FR5969

This project interfaces Temperature and Humidity Sensor Pro(DHT22) with MSP430FR5969 MCU.

Working: Function getTemperatureAndHumidity() will trigger DHT22 and will read Temperature and Humidity.
After reading them, they will be converted and stored in "temperatureAndHumidityBuffer" string.

The system enters LPM3 and WDT will wake the system up every 16 seconds. System will take value and will go to sleep again.

Reading Temperature and Humidity:

1. Trigger sensor by sending 40µSeconds low pulse followed by 40µSeconds High pulse. Configure the pin as input and select raising ede interrupt
2. Ignore the first two transitions since those transitions arent related to Temperature or Humidity
3. Start Timer(TimerB) on raising edges and stop it on Falling Edge. Count the number of µSeconds elapsed
4. If the pulse is high for >30µSec, then consider the bit as 1 or consider it as 0
5. Put the MCU in sleep as long as possible.
6. If you prefer the Fahrenheit scale, please make FAHRENHEIT flag in mainApp.h to true.

In this project, TimerB has been configured to tick once every 10µSeconds. So, if the pulsewidth is 5, it means that the pulse is high for around 50 µSeconds
