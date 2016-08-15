//05.08.2016
#ifndef LINE_H
#define LINE_H

#include "Sensor.h"

class Line : public Sensor <float>
{
  public:
    Line(int _sensorCount, int _sensors[], int _weight[], int _white[], int _black[]);
    void call();
    float getDark();
    float getValue();
  private:
    void calk();
    void readSensors();
    float dark;
    int *weight;
    int *white;
    int *black;
    int *znachenieSensor;
    float *linePro;
};
#endif
