#include "Sensor.h"

template <typename T>
Sensor<T>::Sensor(int _sensorCount, int _pins[])
:sensorCount(_sensorCount)
{
  pins = new int [sensorCount];

  for(int i = 0; i<sensorCount; i++)
  {
    pins[i] = _pins[i];
  } 
}

template <typename T>
T Sensor<T>::getValue()
{
  return value;
}

