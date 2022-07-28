#include "constants.h"
#include "sensors.h"
#include "motors.h"
#include "servo_motors.h"
#include "fire.h"

char op;
int val;
bool scaning = false;

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
  sensorsSetup();
  motorsSetup();
  servoSetup();
  fireSetup();
}

void loop() {
  while(Serial3.available()){
    op = char(Serial3.read());
    Serial.println(op);

    switch(op){ 
      case 'f': fire(); break;
      case 'o': jaw(OPEN); break;
      case 'c': jaw(CLOSE); break;
      case 'm': //Speed
        val = Serial3.readStringUntil(';').substring(1).toInt();
        changeSpeed(val);
        break;
      case 'l': //Arm
        val = Serial3.readStringUntil(';').substring(1).toInt();
        servo1Movement(val);
        break;
      case 'r': servo2Up(); break;
      case 't': servo2Down(); break;
      case 'u': scaning = true; break;
      case 'p': scaning = false;break;
      default: move(op); break;
    }
  }
  if(scaning) scan();
}
