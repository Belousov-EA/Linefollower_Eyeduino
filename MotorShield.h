//23.07.2016
#ifndef MOTOR_SHIELD_H
#define MOTOR_SHIELD_H

#include "Motor.h"

class MotorShield
{
  public:
    MotorShield(int lPower, int lDirection, int rPower, int rDirection);
    void init();
    void setPower(float leftP, float rightP);
  private:
    Motor left;
    Motor right;
    
};
#endif
