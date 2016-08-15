//05.08.2016
#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

template <typename T>
class Sensor
{
  public:
    Sensor(int _sencorCount, int _pins[]);
    inline T getValue();
    void debug();
  protected:
    T value;
    int *pins;
    int sensorCount;
};

#endif
