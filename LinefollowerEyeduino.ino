#include "LineFollower.h"

LineFollower bot(int DistancePin, int sensorCount, int sensors[],
      int weight[], int white[], int black[], int lPower, int lDirection,
      int rPower, int rDirection, float lowP, float lowD, float lowSpeed,
      float highSpeed, float highP, float highD, float cameraStep);

void setup() 
{
  bot.init();
  //bot.initDebug();
}

void loop() 
{
  bot.call();
  //bot.debug();
}
