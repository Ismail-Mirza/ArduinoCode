#include <Arduino.h>



int motor1pin1 = 11;
int motor1pin2 = 12;
int motor1pinEn = 8;

int motor2pin1 =9;
int motor2pin2 = 10;
int motor2pinEn = 7;
int trigPin = 8;
int echoPin = 7;
long duration;
int distance;

void setup()
{
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  // pinMode(motor1pinEn,OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  // pinMode(motor2pinEn,OUTPUT);
  pinMode(trigPin, OUTPUT);                         // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);                          // Sets the echoPin as an INPUT
  Serial.begin(9600);                               // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}

void loop()
{
  // put your main code here, to run repeatedly:
  // analogWrite(motor1pinEn,255);
  // analogWrite(motor2pinEn,255);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(1000);
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
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}