#include "Motor.h"

Motor::Motor(int pPin, int dPin)
:powerPin(pPin),
directionPin(dPin)
{
  //empty body
}


void Motor::setPower(int power, bool direction)
{
  digitalWrite(directionPin, direction);
  analogWrite(powerPin, power);
}


void Motor::init()
{
  pinMode(directionPin, OUTPUT);
}

