#include <Arduino.h>
#include <Servo.h>
Servo servo[12];
const int servo_pin[12] = {2,3,4,5,6,7,8,9,10,11,40,13};

void setup() {
  // put your setup code here, to run once:
    //initialize all servos
    for(int i=0;i<12;i++)
    {
      servo[i].attach(servo_pin[i]);
    }
}

void loop() {
  // put your main code here, to run repeatedly:

    for (int i=0;i<12;i++)
    {
      servo[i].write(0);
      delay(200);
      servo[i].write(90);
      delay(200);
    }


}
