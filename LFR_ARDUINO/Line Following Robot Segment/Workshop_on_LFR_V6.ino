//declaring global detectopm
int speed = 100;     // MAX 255
int turn_delay = 10;

// L293 Connection
const int motorApin1 = 7;
const int motorApin2 = 6;
const int motorAspeed = 5;
const int motorBpin1 = 9;
const int motorBpin2 = 8;
const int motorBspeed = 10;

// Sensor Connection
const int left_sensor_pin = A0;
const int right_sensor_pin = A1;
int left_sensor_state;
int right_sensor_state;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorBpin1, OUTPUT);
  pinMode(motorBpin2, OUTPUT);
  pinMode(motorApin1, OUTPUT);
  pinMode(motorApin2, OUTPUT);

  Serial.begin(9600);

  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  left_sensor_state = analogRead(left_sensor_pin);

  right_sensor_state = analogRead(right_sensor_pin);
  Serial.print("left sensor:");
  Serial.println(left_sensor_state);
  Serial.print("Right Sensor:");
  Serial.println(right_sensor_state);

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



void takeRight(int speed){
  motorRightBackward();
  motorLeftForward();

  analogWrite(motorAspeed, speed);
  analogWrite(motorBspeed, speed);
}
// function for take right 
/*
      One 

*/
void takeLeft(int speed){
  motorRightForward();
  motorLeftBackward();

  analogWrite(motorAspeed, speed);
  analogWrite(motorBspeed, speed);

  delay(turn_delay);
}

void goStraight(int speed)
{
  motorLeftForward();
  motorRightForward();
  analogWrite(motorAspeed, speed);
  analogWrite(motorBspeed, speed);

  delay(turn_delay);
}
//left motor rotates counter clockwise
void motorLeftBackward()
{
  digitalWrite(motorBpin2, LOW);
  digitalWrite(motorBpin1, HIGH);
}
// left motor rotates clockwise
void motorLeftForward()
{
  digitalWrite(motorBpin2, HIGH);
  digitalWrite(motorBpin1, LOW);
}
//right motor rotates counter clockwise
void motorRightBackward()
{
  digitalWrite(motorApin2, LOW);
  digitalWrite(motorApin1, HIGH);
}
// right motor rotates clockwise
void motorRightForward()
{
  digitalWrite(motorApin2,HIGH);
  digitalWrite(motorApin1,LOW);
}
//mootor stop
void stop()
{
  analogWrite(motorAspeed, 0);
  analogWrite(motorBspeed, 0);
}
