#include "constants.h"
#include <Arduino.h>

void motorMotion(int motorNumber, int motorDirection);
void motorsSetup();
void move(char cmd);
void changeSpeed(int s);
void left();
void right();
void forward();
void backward();
void stop();
