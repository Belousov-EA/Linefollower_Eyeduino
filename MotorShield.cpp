#include "MotorShield.h"

MotorShield::MotorShield(int lPower, int lDirection, int rPower, int rDirection)
:left(lPower, lDirection),
right(rPower, rDirection)
{
  //an empty body
}


void MotorShield::init()
{
  left.init();
  right.init();
}


void MotorShield::setPower(float leftP, float rightP)
{
  left.setPower(constrain(abs(leftP*255), 0, 255), leftP>0?0:1);
  right.setPower(constrain(abs(rightP*255), 0, 255), rightP>0?0:1);
}

