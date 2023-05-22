#include <DHT.h>
#include <DHT_U.h>




#define DHTTYPE DHT22   // DHT 22  (AM2302)


#define DHT22_PIN 4
DHT dht(DHT22_PIN, DHTTYPE);
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
  dht.begin();
}

// the loop function runs over and over again forever
void loop() {
  
   float t = dht.readTemperature();
     if ( (t  >= 23) && (t<= 28)){
  quick_blink(3); // turn the LED on (HIGH is the voltage level) yelow
   digitalWrite(0, LOW);
   digitalWrite(1, LOW);
    digitalWrite(2, LOW);
  
   }
   if  ((t>=0) && (t<=23)){
  quick_blink(2);  // turn the LED on (HIGH is the voltage level) green
    digitalWrite(0, LOW);
   digitalWrite(1, LOW);
    digitalWrite(3, LOW);
  
  
   }
    if  (t>=28) {
   quick_blink(0) ; // turn the LED on (HIGH is the voltage level) red
    digitalWrite(2, LOW);
   digitalWrite(1, LOW);
    digitalWrite(3, LOW);
  
   }
   if (t<0){  //low
 quick_blink(1);  // turn the LED on (HIGH is the voltage level) green
    digitalWrite(0, LOW);
   digitalWrite(2, LOW);
    digitalWrite(3, LOW); }
   delay(5000);    
             // wait for a second
    // turn the LED off by making the voltage LOW
                    // wait for a second
}
