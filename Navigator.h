//10.08.2016
#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include "PdRegulator.h"
#include "Camera.h"

class Navigator : public PdRegulator
{
  public:
    Navigator(float _lowP, float _lowD, float _lowSpeed, float _highSpeed, float _highP, float _highD, float _step);
    void call(float error);
    void init();
    float getSpeed();
    void debug();
  private:
    float lowP;
    float lowD;
    float lowSpeed;
    float highSpeed;
    float highP;
    float highD;
    Camera myCamera;
    float step;
    float speed;
    
};
#endif
