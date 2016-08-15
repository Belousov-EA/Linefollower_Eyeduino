#include "Distance.h"

Distance::Distance(int pin)
:Sensor(1, &pin )
{
  
}


void Distance::call()
{
  value = !digitalRead(pins[0]);
}


void Distance::init()
{
  pinMode(pins[0], INPUT);
}

