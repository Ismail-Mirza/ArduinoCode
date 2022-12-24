#include <Arduino.h>
#include <Servo.h>
Servo servo1;
void setup() {
  // put your setup code here, to run once:
  servo1.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Make servo go to 0 degrees 
   servo1.write(0); 
   delay(1000); 
   // Make servo go to 90 degrees 
   servo1.write(90); 
   delay(1000); 
   // Make servo go to 180 degrees 
   servo1.write(180); 
   delay(1000);
}