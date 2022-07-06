#include "constants.h"


int speed = 0;

void setup() {
  
}

void loop() {
  

}

//Movement
void move(int dir){
  switch(dir){
    case FRONT:
      Forward();
      break;
    case BACK:
      Backward();
      break;
    case RIGHT:
      Right();
      break;
    case LEFT:
      Left();
      break;
    case TURNLEFT:
      TURN_LEFT();
      break;
    case TURNRIGHT:
      TURN_RIGHT();
      break;
    case FRONT_RIGHT:
      FRONTRIGHT();
      break;
    case FRONT_LEFT:
      FRONTLEFT();
      break;
    case BACK_RIGHT:
      backRight();
      break;
    case BACK_LEFT:
      backLeft();
      break;
    default:
      Stop();
      break;
  }
}

void stop(){
  
}

void changeSpeed(int s){
  int pwmoutput= map(s,0,100,0,255);
  analogWrite(FRM_SPEED,pwmoutput);
  analogWrite(FLM_SPEED,pwmoutput);
  analogWrite(BLM_SPEED,pwmoutput);
  analogWrite(BRM_SPEED,pwmoutput);
}

//Arm
void moveArm(int op){
  
}

void fire(){
  
}

//Sensors
int distance(int dir){
  
}
//magdy part
/*void setUP_Motors(){
  pinMode(FRM_SPEED,OUTPUT);
  pinMode(FRM_IN1,OUTPUT);
  pinMode(FRM_IN2,OUTPUT);
    pinMode(FLM_SPEED,OUTPUT);
  pinMode(FLM_IN1,OUTPUT);
  pinMode(FLM_IN2,OUTPUT);
      pinMode(BRM_SPEED,OUTPUT);
  pinMode(BRM_IN1,OUTPUT);
  pinMode(BRM_IN2,OUTPUT);
       pinMode(BLM_SPEED,OUTPUT);
  pinMode(BLM_IN1,OUTPUT);
  pinMode(BLM_IN2,OUTPUT);
  
}*/
struct MOTOR_PINS
{
  int pinIN1;
  int pinIN2;    
};
 MOTOR_PINS motorPins[] = 
{
  {FRM_IN1 , FRM_IN2},  //FRONT_RIGHT_MOTOR
  {BRM_IN1 , BRM_IN2},  //BACK_RIGHT_MOTOR
  {FLM_IN1 , FLM_IN2},  //FRONT_LEFT_MOTOR
  {BLM_IN1 , BLM_IN1},  //BACK_LEFT_MOTOR   
};
//setup pins
void setUpPinModes()
{
  for (int i = 0; i < 4; i++)
  {
    pinMode(motorPins[i].pinIN1, OUTPUT);
    pinMode(motorPins[i].pinIN2, OUTPUT);  
    motorMotion(i, STOP);  
  }
}

// motor motion
void motorMotion(int motorNumber, int motorDirection)
{
  if (motorDirection == FORWARD)
  {
    digitalWrite(motorPins[motorNumber].pinIN1, HIGH);
    digitalWrite(motorPins[motorNumber].pinIN2, LOW);    
  }
  else if (motorDirection == BACKWARD)
  {
    digitalWrite(motorPins[motorNumber].pinIN1, LOW);
    digitalWrite(motorPins[motorNumber].pinIN2, HIGH);     
  }
  else
  {
    digitalWrite(motorPins[motorNumber].pinIN1, LOW);
    digitalWrite(motorPins[motorNumber].pinIN2, LOW);       
  }
}
//car motion funcions 
void Forward(){
      motorMotion(FRM, FORWARD);
      motorMotion(BRM, FORWARD);
      motorMotion(FLM, FORWARD);
      motorMotion(BLM, FORWARD);  
}
void Backward(){
      motorMotion(FRM, BACKWARD);
      motorMotion(BRM, BACKWARD);
      motorMotion(FLM, BACKWARD);
      motorMotion(BLM, BACKWARD); 
}
void Left(){
 
     motorMotion(FRM,FORWARD );
     motorMotion(BRM, BACKWARD);
     motorMotion(FLM, BACKWARD);
     motorMotion(BLM, FORWARD); 
}
void Right(){
     motorMotion(FRM,BACKWARD );
     motorMotion(BRM, FORWARD);
     motorMotion(FLM, FORWARD);
     motorMotion(BLM, BACKWARD); 
}
void TURN_RIGHT(){
      motorMotion(FRM, BACKWARD);
      motorMotion(BRM, BACKWARD);
      motorMotion(FLM, FORWARD);
      motorMotion(BLM, FORWARD); 
}
void TURN_LEFT(){
      motorMotion(FRM, FORWARD);
      motorMotion(BRM, FORWARD);
      motorMotion(FLM, BACKWARD);
      motorMotion(BLM, BACKWARD); 
}
void Stop(){
      motorMotion(FRM, STOP);
      motorMotion(BRM, STOP);
      motorMotion(FLM, STOP);
      motorMotion(BLM, STOP);
}
//crab walk modes
void FRONTLEFT(){
      motorMotion(FRM,FORWARD );
      motorMotion(BRM, STOP);
      motorMotion(FLM, STOP);
      motorMotion(BLM, FORWARD); 
}
void FRONTRIGHT(){
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
