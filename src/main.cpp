
#include "TM1637.h"
#include <Wire.h>
#include "DHTesp.h" // Click here to get the library: http://librarymanager/All#DHTesp

// PWM output pin
const byte DHT_Pin = 5;
const byte CLK = 12;            //ESp32 GPIO2
const byte DIO = 13;           // ESP32 GPIO4

DHTesp dht;             // instantiate a DHT object
TM1637 tm;                 // Instantiate a tm object
bool colon = false;



void setup() {
  Serial.begin(115200);
  	// Start up the temperature library 
  dht.setup(DHT_Pin, DHTesp::DHT11);   // If you are using the DHT22, you just need to change the value 11 to 22
  delay(dht.getMinimumSamplingPeriod());
  Serial.println(dht.getStatusString());
 
    //begin the 4 digit led
  tm.begin(CLK, DIO, 4);  //Clock, Data In-Out, digit number
  tm.displayClear();
  tm.setBrightness(7);     // full brightness, default is 3

}

void loop() {
  float temp = dht.getTemperature();       // To store the values of tempreature
  tm.displayCelsius(temp, colon); // display the numbers
  colon = !colon;         // toggle colon
  delay(1000);
}

