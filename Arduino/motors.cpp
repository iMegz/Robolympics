#include "motors.h"
#include "sensors.h"

struct MOTOR_PINS{
  int pinIN1;
  int pinIN2;    
};

MOTOR_PINS motorPins[] = {
  {FRM_IN1 , FRM_IN2},  //FRONT_RIGHT_MOTOR
  {BRM_IN1 , BRM_IN2},  //BACK_RIGHT_MOTOR
  {FLM_IN1 , FLM_IN2},  //FRONT_LEFT_MOTOR
  {BLM_IN1 , BLM_IN2},  //BACK_LEFT_MOTOR   
};

//setup pins
void motorsSetup(){
  for (int i = 0; i < 4; i++){
    pinMode(motorPins[i].pinIN1, OUTPUT);
    pinMode(motorPins[i].pinIN2, OUTPUT);  
    //motorMotion(i, STOP);  
  }
  digitalWrite(FRM_SPEED,HIGH);
  digitalWrite(FLM_SPEED,HIGH);
  digitalWrite(BRM_SPEED,HIGH);
  digitalWrite(BLM_SPEED,HIGH);
}

//Movement
void move(char cmd){
  switch(cmd){
    case 'w': forward(); break;
    case 's': backward(); break;
    case 'd': right(); break;
    case 'a': left(); break;
    default: stop();break;
  }
}


// motor motion
void motorMotion(int motorNumber, int motorDirection){
  switch(motorDirection){
    case FORWARD:
      digitalWrite(motorPins[motorNumber].pinIN1, HIGH);
      digitalWrite(motorPins[motorNumber].pinIN2, LOW);  
      break;
    case BACKWARD:
      digitalWrite(motorPins[motorNumber].pinIN1, LOW);
      digitalWrite(motorPins[motorNumber].pinIN2, HIGH); 
      break;
    default:
      digitalWrite(motorPins[motorNumber].pinIN1, LOW);
      digitalWrite(motorPins[motorNumber].pinIN2, LOW);
      break;
  }
}

//Speed
void changeSpeed(int s){
  int pwmoutput= map(s,0,10,0,255);
  analogWrite(FRM_SPEED,pwmoutput);
  analogWrite(FLM_SPEED,pwmoutput);
  analogWrite(BRM_SPEED,pwmoutput);
  analogWrite(BLM_SPEED,pwmoutput);
}

//car motion funcions 
void forward(){
    motorMotion(FRM, FORWARD);
    motorMotion(BRM, FORWARD);
    motorMotion(FLM, BACKWARD);
    motorMotion(BLM, BACKWARD);
}
void backward(){
      motorMotion(FRM, BACKWARD);
      motorMotion(BRM, BACKWARD);
      motorMotion(FLM, FORWARD);
      motorMotion(BLM, FORWARD); 
}

void left(){
      motorMotion(FRM, FORWARD);
      motorMotion(BRM, FORWARD);
      motorMotion(FLM, FORWARD);
      motorMotion(BLM, FORWARD); 
}
void right(){
      motorMotion(FRM, BACKWARD);
      motorMotion(BRM, BACKWARD);
      motorMotion(FLM, BACKWARD);
      motorMotion(BLM, BACKWARD); 
}
void stop(){
      motorMotion(FRM, STOP);
      motorMotion(BRM, STOP);
      motorMotion(FLM, STOP);
      motorMotion(BLM, STOP);
}
