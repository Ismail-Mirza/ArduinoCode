#include <Arduino.h>

//declaring global detectopm
int speed = 110;     // MAX 255
int turn_delay = 10;

// L293 Connection
const int motorRight1 = 8;
const int motorRight2 = 9;
const int motorRightspeed = 10;
const int motorLeft1 = 7;
const int motorLeft2 = 6;
const int motorLeftspeed = 5;

// Sensor Connection
const int left_sensor_pin = A0;
const int right_sensor_pin = A1;
void  takeRight(int speed);
void  takeLeft(int speed);
void goStraight(int speed);
void motorLeftForward();
void motorLeftBackward();
void motorRightForward();
void motorRightBackward();
void stop();
int left_sensor_state;
int right_sensor_state;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorRight1, OUTPUT);
  pinMode(motorRight2, OUTPUT);
  pinMode(motorLeft1, OUTPUT);
  pinMode(motorLeft2, OUTPUT);
  // pinMode(left_sensor_pin,INPUT);
  // pinMode(right_sensor_pin,INPUT);

  Serial.begin(9600);

  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  left_sensor_state = analogRead(left_sensor_pin);

  right_sensor_state = analogRead(right_sensor_pin);

  if (right_sensor_state > 500 && left_sensor_state < 500)
  {
      //take right
      Serial.print("Take right taken\n");
      takeRight(speed);

  }
  else if (right_sensor_state<500 && left_sensor_state>500)
  {
    //take left
    Serial.print("Take left\n");
    takeLeft(speed);
  }
  else if ( right_sensor_state<500 && left_sensor_state<500)
  {
     // go straight
     Serial.write("Go Straight\n");
     goStraight(speed);
  }
  else
  {
    // stop
    Serial.write("Stop\n");
    stop();
  }
}



void takeLeft(int speed){
  motorRightBackward();
  motorLeftForward();

  analogWrite(motorRightspeed, speed);
  analogWrite(motorLeftspeed, speed);
}

void takeRight(int speed){
  motorRightForward();
  motorLeftBackward();

  analogWrite(motorRightspeed, speed);
  analogWrite(motorLeftspeed, speed);

  delay(turn_delay);
}

void goStraight(int speed)
{
  motorLeftForward();
  motorRightForward();

  analogWrite(motorRightspeed, speed);
  analogWrite(motorLeftspeed, speed);

  delay(turn_delay);
}

void motorLeftForward()
{
  digitalWrite(motorLeft2, HIGH);
  digitalWrite(motorLeft1, LOW);
}
void motorLeftBackward()
{
  digitalWrite(motorLeft2, LOW);
  digitalWrite(motorLeft1, HIGH);
}
//motor right
void motorRightForward()
{
  digitalWrite(motorRight2, HIGH);
  digitalWrite(motorRight1, LOW);
}
void motorRightBackward()
{
  digitalWrite(motorRight2,LOW);
  digitalWrite(motorRight1, HIGH);
}
void stop()
{
  analogWrite(motorRightspeed, 0);
  analogWrite(motorLeftspeed, 0);
}