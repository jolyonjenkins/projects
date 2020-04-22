///////////////////////////////////////////////////////////////////////////////
// BMP280_DEV - SPI Communications, Default Configuration, Normal Conversion
///////////////////////////////////////////////////////////////////////////////
/*
Module pin 1 to Arduino  3.3V pin
Module pin 2 to Arduino  GND pin
Module pin 3 (SCK) to Arduino  pin 13
Module pin 4 (SDI) to Arduino  pin 11
Module pin 5 (CSB or CS) to Arduino  pin 10 / 9
Module pin 6 (SDO) to Arduino pin 12
*/

#include <BMP280_DEV.h>                             // Include the BMP280_DEV.h library

float temperature, pressure, altitude;              // Create the temperature, pressure and altitude variables
BMP280_DEV bmp280_1(10);                            // Instantiate (create) a BMP280_DEV object and set-up for SPI operation on digital pin D10
BMP280_DEV bmp280_2(9);                             // Instantiate (create) a BMP280_DEV object and set-up for SPI operation on digital pin D9

void setup()
{
  Serial.begin(9600);                             // Initialise the serial port
  bmp280_1.begin();                                 // Default initialisation, place the BMP280_1 into SLEEP_MODE
  bmp280_1.setTimeStandby(TIME_STANDBY_2000MS);     // Set the standby time to 2 seconds
  bmp280_1.startNormalConversion();                 // Start BMP280_1 continuous conversion in NORMAL_MODE
  bmp280_2.begin();                                 // Default initialisation, place the BMP280_2 into SLEEP_MODE
  bmp280_2.setTimeStandby(TIME_STANDBY_2000MS);     // Set the standby time to 2 seconds
  bmp280_2.startNormalConversion();                 // Start BMP280_2 continuous conversion in NORMAL_MODE 
}

void loop()
{
  if (bmp280_1.getMeasurements(temperature, pressure, altitude))    // Check if the measurement is complete
  {
    Serial.print(F("BMP280_1 "));
    Serial.print(temperature);                      // Display the results   
    Serial.print(F("*C   "));
    Serial.print(pressure);   
    Serial.print(F("hPa   "));
    Serial.print(altitude);
    Serial.println(F("m")); 
  }
  if (bmp280_2.getMeasurements(temperature, pressure, altitude))    // Check if the measurement is complete
  {
    Serial.print(F("BMP280_2 "));
    Serial.print(temperature);                      // Display the results   
    Serial.print(F("*C   "));
    Serial.print(pressure);   
    Serial.print(F("hPa   "));
    Serial.print(altitude);
    Serial.println(F("m")); 
  }
}
