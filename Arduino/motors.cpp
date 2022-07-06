#include "motors.h"

struct MOTOR_PINS{
  int pinIN1;
  int pinIN2;    
};

MOTOR_PINS motorPins[] = {
  {FRM_IN1 , FRM_IN2},  //FRONT_RIGHT_MOTOR
  {BRM_IN1 , BRM_IN2},  //BACK_RIGHT_MOTOR
  {FLM_IN1 , FLM_IN2},  //FRONT_LEFT_MOTOR
  {BLM_IN1 , BLM_IN1},  //BACK_LEFT_MOTOR   
};

//setup pins
void motorsSetup(){
  for (int i = 0; i < 4; i++){
    pinMode(motorPins[i].pinIN1, OUTPUT);
    pinMode(motorPins[i].pinIN2, OUTPUT);  
    motorMotion(i, STOP);  
  }
}

//Movement
void move(int dir){
  switch(dir){
    case FRONT: forward(); break;
    case BACK: backward(); break;
    case RIGHT: right(); break;
    case LEFT: left(); break;
    case TURN_LEFT: turnLeft(); break;
    case TURN_RIGHT: turnRight(); break;
    case FRONT_RIGHT: frontRight(); break;
    case FRONT_LEFT: frontLeft(); break;
    case BACK_RIGHT: backRight(); break;
    case BACK_LEFT: backLeft(); break;
    default: stop();break;
  }
}


// motor motion
void motorMotion(int motorNumber, int motorDirection){
  if (motorDirection == FORWARD){
    digitalWrite(motorPins[motorNumber].pinIN1, HIGH);
    digitalWrite(motorPins[motorNumber].pinIN2, LOW);    
  }else if (motorDirection == BACKWARD){
    digitalWrite(motorPins[motorNumber].pinIN1, LOW);
    digitalWrite(motorPins[motorNumber].pinIN2, HIGH);     
  }else{
    digitalWrite(motorPins[motorNumber].pinIN1, LOW);
    digitalWrite(motorPins[motorNumber].pinIN2, LOW);       
  }
}

//Speed
void changeSpeed(int s){
  int pwmoutput= map(s,0,100,0,255);
  analogWrite(SPEED,pwmoutput);
  analogWrite(SPEED,pwmoutput);
  analogWrite(SPEED,pwmoutput);
  analogWrite(SPEED,pwmoutput);
}

//car motion funcions 
void forward(){
      motorMotion(FRM, FORWARD);
      motorMotion(BRM, FORWARD);
      motorMotion(FLM, FORWARD);
      motorMotion(BLM, FORWARD);  
}
void backward(){
      motorMotion(FRM, BACKWARD);
      motorMotion(BRM, BACKWARD);
      motorMotion(FLM, BACKWARD);
      motorMotion(BLM, BACKWARD); 
}
void left(){
 
     motorMotion(FRM,FORWARD );
     motorMotion(BRM, BACKWARD);
     motorMotion(FLM, BACKWARD);
     motorMotion(BLM, FORWARD); 
}
void right(){
     motorMotion(FRM,BACKWARD );
     motorMotion(BRM, FORWARD);
     motorMotion(FLM, FORWARD);
     motorMotion(BLM, BACKWARD); 
}
void turnLeft(){
      motorMotion(FRM, BACKWARD);
      motorMotion(BRM, BACKWARD);
      motorMotion(FLM, FORWARD);
      motorMotion(BLM, FORWARD); 
}
void turnRight(){
      motorMotion(FRM, FORWARD);
      motorMotion(BRM, FORWARD);
      motorMotion(FLM, BACKWARD);
      motorMotion(BLM, BACKWARD); 
}
void stop(){
      motorMotion(FRM, STOP);
      motorMotion(BRM, STOP);
      motorMotion(FLM, STOP);
      motorMotion(BLM, STOP);
}
//crab walk modes
void frontLeft(){
      motorMotion(FRM,FORWARD );
      motorMotion(BRM, STOP);
      motorMotion(FLM, STOP);
      motorMotion(BLM, FORWARD); 
}
void frontRight(){
      motorMotion(FRM,STOP);
      motorMotion(BRM,FORWARD );
      motorMotion(FLM,FORWARD);
      motorMotion(BLM,STOP );
}
void backLeft(){
      motorMotion(FRM,STOP);
      motorMotion(BRM, BACKWARD);
      motorMotion(FLM,BACKWARD);
      motorMotion(BLM,STOP );
}
void backRight(){
      motorMotion(FRM,BACKWARD );
      motorMotion(BRM, STOP);
      motorMotion(FLM, STOP);
      motorMotion(BLM, BACKWARD); 
}
