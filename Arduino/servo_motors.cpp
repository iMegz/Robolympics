#include "servo_motors.h"

Servo servo1;
Servo servo2;
Servo servoGrip;

//intial values for servos maybe changed while testing  
int servo_1_degree = SERVO_1_INIT;
int servo_2_degree = SERVO_2_INIT;

void servoSetup(){
  servo1.attach(SERVO_1);
  servo2.attach(SERVO_2);
  servoGrip.attach(JAW);
}

void servo2Up(){
   servo_2_degree += ANGLE_CHANGE;
   servo_2_degree = min(145, max(15, servo_2_degree));
   servo2.write(servo_2_degree);  
}
void servo2Down(){
   servo_2_degree -= ANGLE_CHANGE;
   servo_2_degree = min(145, max(15, servo_2_degree));
   servo2.write(servo_2_degree);  
}
void servo1Movement(int y){
     servo_1_degree = map(y, 0, 180, 0, 150);
     servo1.write(servo_1_degree);
}
void jaw(int openOrClose){
  servoGrip.write(openOrClose);
}
//void openGrip(){
//   servoGrip.write(90);
//}
//void closeGrip(){
//   servoGrip.write(180);
//}
