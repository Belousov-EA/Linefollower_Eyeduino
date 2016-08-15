//10.08.2016
#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#include "Distance.h"
#include "Line.h"
#include "MotorShield.h"
#include "Navigator.h"

class LineFollower
{
  public:
    LineFollower(int DistancePin, int sensorCount, int sensors[],
      int weight[], int white[], int black[], int lPower, int lDirection,
      int rPower, int rDirection, float lowP, float lowD, float lowSpeed,
      float highSpeed, float highP, float highD, float cameraStep);
    void init();
    void call();
    void debug();
    void initDebug();
  private:
    void vozvrat();
    void motorCount();
    void tormoz();
    float lastExc;
    int temno;
    Distance forward;
    Line exc;
    MotorShield motor;
    Navigator myNavigator;
    
};
#endif
