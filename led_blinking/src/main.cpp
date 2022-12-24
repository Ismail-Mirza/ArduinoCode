#include <Arduino.h>
void measureDistance(int trigPin,int echoPin,char sonar[]);
int rightEchoPin = 13;
int rightTrigPin = 12;
int leftTrigPin = 9;
int leftEchoPin = 8;
int middleTrigPin = 11;
int middleEchoPin = 10;
//for motor
int motor1pin1 = 6;
int motor1pin2 = 7;
int motor2pin3 = 4;
int motor2pin4 = 5;
int enA = 3;
int enB = 2;
long duration;
int distance;

void setup()
{
  // put your setup code here, to run once:
  pinMode(leftTrigPin, OUTPUT);                         // Sets the trigPin as an OUTPUT
  pinMode(leftEchoPin, INPUT);                          // Sets the echoPin as an INPUT
  pinMode(rightTrigPin, OUTPUT);                         // Sets the trigPin as an OUTPUT
  pinMode(rightEchoPin, INPUT);                          // Sets the echoPin as an INPUT
  pinMode(middleTrigPin, OUTPUT);                         // Sets the trigPin as an OUTPUT
  pinMode(middleEchoPin, INPUT);
  //for motor 
  pinMode(motor1pin1,OUTPUT);
  pinMode(motor1pin2,OUTPUT);
  pinMode(motor2pin3,OUTPUT);
  pinMode(motor2pin4,OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
                          // Sets the echoPin as an INPUT
  Serial.begin(9600);                               // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}

void loop()
{
  analogWrite(enA,255);
  analogWrite(enB,255);
  digitalWrite(motor1pin1,HIGH);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin3,HIGH);
  digitalWrite(motor2pin4,LOW);
  delay(1000);

  measureDistance(leftTrigPin,leftEchoPin,"Left sonar");
  measureDistance(rightTrigPin,rightEchoPin,"Right sonar");
  measureDistance(middleTrigPin,middleEchoPin,"Middle sonar");
  // measureDistance(leftTrigPin,leftEchoPin,"Left sonar");
}
void measureDistance(int trigPin,int echoPin,char sonar[]){
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  if(distance<=20){
    Serial.print(sonar);
    Serial.print(" ");
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  else
  {
    Serial.println('.');
  }
}