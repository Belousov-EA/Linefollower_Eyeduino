#include "Navigator.h"

Navigator::Navigator(float _lowP, float _lowD, float _lowSpeed, float _highSpeed, float _highP, float _highD, float _step)
:PdRegulator(highP, highD),
lowP(_lowP),
lowD(_lowD),
lowSpeed(_lowSpeed),
highSpeed(_highSpeed),
highP(_highP),
highD(_highD),
step(_step)

{
  
}


void Navigator::init()
{
  myCamera.init();
}


float Navigator::getSpeed()
{
  return speed;
}


void  Navigator::call(float error)
{
  myCamera.call();
  if(myCamera.getValue()<step)
  {
    speed = highSpeed;
    p = highP;
    d = highD;
  }else
  {
    speed = lowSpeed;
    p = lowP;
    d = lowD;
  }
  toRegulate(error);
}

