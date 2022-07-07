#include "constants.h"
#include "sensors.h"
#include "motors.h"

char op;
int val;

void setup() {
  Serial.begin(9600);
  sensorsSetup();
  motorsSetup();
}

void loop() {
  while(Serial.available()){
    op = Serial.read();
    switch(op){ 
      case 'f': 
        fire();
        break;
      case 'o':
        moveArm(OPEN);
        digitalWrite(13, HIGH);
        break;
      case 'c':
        moveArm(CLOSE);
        digitalWrite(13, LOW);
        break;
      case 'm': //Speed
        val = Serial.readStringUntil(';').substring(1).toInt();
        changeSpeed(val);
        break;
      case 'l': //Arm
        val = Serial.readStringUntil(';').substring(1).toInt();
        //Move arm
        break;
      case 'u': 
        scan();
        break;
      default:
        move(op);
        break;
    }
  }
}

//Arm
void moveArm(int op){
  
}

void fire(){
  
}
