#include "sensors.h"
void scan(){
  String data = "";
  int d;
  
  d = distance(FRONT); //Orange
  data = "1:" + String(d) + ';';
  Serial3.println(data);
  Serial.println(data);
  delay(80);

  d = distance(RIGHT); //Yellow
  data = "2:" + String(d) + ';';
  Serial3.println(data);
  Serial.println(data);
  delay(80);

  d = distance(LEFT); //Brown
  data = "3:" + String(d) + ';';
  Serial3.println(data);
  Serial.println(data);
  delay(80);
}

void scanTest(){
  String data = "";
  int d;
  d = distance(FRONT);
  Serial.print("Front : ");
  Serial.print(d);
  Serial.println(" cm");

  d = distance(RIGHT);
  Serial.print("Right : ");
  Serial.print(d);
  Serial.println(" cm");

  d = distance(LEFT);
  Serial.print("Left : ");
  Serial.print(d);
  Serial.println(" cm");
}

void sensorsSetup(){
  pinMode(FRONT_TRIG, OUTPUT);
  pinMode(RIGHT_TRIG, OUTPUT);
  pinMode(LEFT_TRIG, OUTPUT);
  
  pinMode(FRONT_ECHO, INPUT);
  pinMode(RIGHT_ECHO, INPUT);
  pinMode(LEFT_ECHO, INPUT);
}

float distance(int dir){
  float duration_us, distance_cm;

  switch(dir){
    case FRONT:
      trig(FRONT_TRIG);
      duration_us = pulseIn(FRONT_ECHO, HIGH); 
      break;
   case RIGHT:
      trig(RIGHT_TRIG);
      duration_us = pulseIn(RIGHT_ECHO, HIGH); 
      break;
   case LEFT:
      trig(LEFT_TRIG);
      duration_us = pulseIn(LEFT_ECHO, HIGH); 
      break;
  }

  //Calculate distance
  distance_cm = 0.017 * duration_us;
  return (distance_cm);
}

void trig(int pinNumber){
  digitalWrite(pinNumber, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinNumber, LOW);
}
