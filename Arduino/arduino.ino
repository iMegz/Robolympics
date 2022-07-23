#include "constants.h"
#include "sensors.h"
#include "motors.h"

char op;
int val;
bool scaning = false;

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
  sensorsSetup();
  motorsSetup();
}

void loop() {
//  scanTest();
//  Serial.println("---------------------------");
//  delay(2500);
  
  while(Serial3.available()){
    op = Serial3.read();
    Serial.println(op);
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
        scaning = true;
        break;
      case 'p': 
        scaning = false;
        break;
      default:
        move(op);
        break;
    }
  }
  if(scaning) scan();
}

//Arm
void moveArm(int op){
  
}

void fire(){
  
}
