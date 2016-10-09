//05.08.2016
#ifndef CAMERA_H
#define CAMERA_H

#include "Sensor.h"

class Camera : public Sensor<float>
{
  public:
    Camera();
    void init();
    void call();
    
};
#endif
