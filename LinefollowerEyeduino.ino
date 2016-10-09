#include "LineFollower.h"

//дальномер
int distancePin = 7;

//линейка сенсоров
const int sensorCount = 8;
int sensors[sensorCount] = {9, 8, 7, 6, 11, 10, 1, 0};
int weight [sensorCount] = {-4,-3,-2,-1,1,2,3,4};
int white [sensorCount] = {72,  61,  61 , 65,  62,  60,  62,  65  };
int black [sensorCount] = {783,  683, 647, 711, 670, 600, 663, 734 };

//мотор
int lPower = 5;
int rPower = 11;
int lDirection = 2;
int rDirection = 3;

//регулятор
float lowP = 1.7;
float lowD = 45;
float lowSpeed = 0.8;
float highP = 1.7;
float highD = 45;
float highSpeed = 0.8;

//камера

float cameraStep = 0.3;

LineFollower bot( distancePin,  sensorCount,  sensors,
       weight,  white,  black,  lPower,  lDirection,
       rPower,  rDirection, lowP, lowD, lowSpeed,
       highSpeed, highP, highD, cameraStep);

void setup() 
{
  bot.init();
  bot.initDebug();
}

void loop() 
{
  bot.call();
  bot.debug();
}
