#include "constants.h"

int speed = 0;

void setup() {
  pinMode(FRONT_TRIG, OUTPUT);
  pinMode(BACK_TRIG, OUTPUT);
  pinMode(RIGHT_TRIG, OUTPUT);
  pinMode(LEFT_TRIG, OUTPUT);
  
  pinMode(FRONT_ECHO, INPUT);
  pinMode(BACK_ECHO, INPUT);
  pinMode(RIGHT_ECHO, INPUT);
  pinMode(LEFT_ECHO, INPUT);
  
}

void loop() {
  


}

//Movement
void move(int dir){

}

void stop(){
  
}

void changeSpeed(int s){
  
}

//Arm
void moveArm(int op){
  
}

void fire(){
  
}

//Sensors
int distance(int dir){
  float duration_us, distance_cm;
  

  switch (dir) {
  case FRONT:
    digitalWrite(FRONT_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(FRONT_TRIG, LOW);
    duration_us = pulseIn(FRONT_ECHO, HIGH);
      
    break;
  case BACK:
    digitalWrite(BACK_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(BACK_TRIG, LOW);
    duration_us = pulseIn(BACK_ECHO, HIGH);
      
    break;
  case RIGHT:
    digitalWrite(RIGHT_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(RIGHT_TRIG, LOW);
    duration_us = pulseIn(RIGHT_ECHO, HIGH);
    break;
    case LEFT:
    digitalWrite(LEFT_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(LEFT_TRIG, LOW);
    duration_us = pulseIn(LEFT_ECHO, HIGH);
  break;
}
distance_cm = 0.017 * duration_us;
return (distance_cm);
}
