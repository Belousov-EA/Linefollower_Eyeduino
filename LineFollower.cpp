#include "LineFollower.h"

LineFollower::LineFollower(int DistancePin, int sensorCount, int sensors[],
    int weight[], int white[], int black[], int lPower, int lDirection,
    int rPower, int rDirection, float lowP, float lowD, float lowSpeed,
    float highSpeed, float highP, float highD, float cameraStep)
:forward(DistancePin),
exc(sensorCount, sensors, weight, white, black),
motor(lPower, lDirection, rPower, rDirection),
myNavigator(lowP, lowD, lowSpeed, highSpeed, highP, highD, cameraStep)
{
  
}



void LineFollower::init()
{
  forward.init();
  motor.init();
  myNavigator.init();
}


void LineFollower::call()
{
  exc.call();
  forward.call();
  if (forward.getValue())
  {
    tormoz();
  }else if(exc.getDark()!=0)
  {
    motorCount();
    lastExc = exc.getValue();
    temno = 0;
  }else
  {
    temno++;
    if(temno>3)
    {
      vozvrat();
    }
  }
}


void LineFollower::motorCount()
{
  myNavigator.call(exc.getValue());
  float reg = myNavigator.getRegulate();
  float left = myNavigator.getSpeed()*(1+reg);
  float right = myNavigator.getSpeed()*(1-reg);
  motor.setPower(left, right);
}


void LineFollower::vozvrat()
{
  if(lastExc>0)
  {
    myNavigator.setPredError(1.00);
    motor.setPower(myNavigator.getSpeed()*(1+myNavigator.getP()), myNavigator.getSpeed()*(1-myNavigator.getP()));
  }else
  {
    myNavigator.setPredError(-1.00);
     motor.setPower(myNavigator.getSpeed()*(1-myNavigator.getP()), myNavigator.getSpeed()*(1+myNavigator.getP()));
  }
}

