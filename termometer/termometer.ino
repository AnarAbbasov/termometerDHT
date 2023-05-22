#include <dht.h>





/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
dht DHT;
#define DHT11_PIN 4


void quick_blink(short led)
{
 digitalWrite(led, HIGH);  
    delay(500);   
    digitalWrite(led, LOW);   
 
}
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
   pinMode(1, OUTPUT);
  digitalWrite(1, LOW);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  pinMode(0, OUTPUT);
  digitalWrite(0, LOW);
}

// the loop function runs over and over again forever
void loop() {
  
   int chk = DHT.read11(DHT11_PIN);
     if ( (DHT.temperature  >= 23) && (DHT.temperature<= 28)){
  quick_blink(3); // turn the LED on (HIGH is the voltage level) yelow
   digitalWrite(0, LOW);
   digitalWrite(1, LOW);
    digitalWrite(2, LOW);
  
   }
   if  ((DHT.temperature>=20) && (DHT.temperature<=23)){
  quick_blink(2);  // turn the LED on (HIGH is the voltage level) green
    digitalWrite(0, LOW);
   digitalWrite(1, LOW);
    digitalWrite(3, LOW);
  
  
   }
    if  (DHT.temperature>=28) {
   quick_blink(0) ; // turn the LED on (HIGH is the voltage level) red
    digitalWrite(2, LOW);
   digitalWrite(1, LOW);
    digitalWrite(3, LOW);
  
   }
   if (DHT.temperature<20){  //low
 quick_blink(1);  // turn the LED on (HIGH is the voltage level) green
    digitalWrite(0, LOW);
   digitalWrite(2, LOW);
    digitalWrite(3, LOW); }
   delay(5000);    
             // wait for a second
    // turn the LED off by making the voltage LOW
                    // wait for a second
}
