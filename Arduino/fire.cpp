#include "fire.h"

void fireSetup(){
  pinMode(FIRE_ENABLE, OUTPUT);
  digitalWrite(FIRE_ENABLE, LOW);
}

void fire(){
  digitalWrite(FIRE_ENABLE, HIGH);
  delay(150);
  digitalWrite(FIRE_ENABLE, LOW);
}
