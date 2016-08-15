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
  _direction = direction;
  _power = power;
}


void Motor::init()
{
  pinMode(directionPin, OUTPUT);
}


void Motor::debug()
{
  Serial.print ("power =");
  Serial.print (_power);
  Serial.print (" derection =");
  Serial.print (_derection);
  Serial.print (" ");
}

