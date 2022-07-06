#include "constants.h"
#include "sensors.h"
#include "motors.h"

int speed = 0;

void setup() {
  Serial.begin(9600);
  sensorsSetup();
  motorsSetup();
}

void loop() {
  
}

//Arm
void moveArm(int op){
  
}

void fire(){
  
}
