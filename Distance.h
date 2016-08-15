//05.08.2016
#ifndef DISTANCE_H
#define DISTANCE_H

#include "Sensor.h"

class Distance : public Sensor <bool>
{
  public:
    Distance(int pin);
    void call();
    void init();
};

#endif
