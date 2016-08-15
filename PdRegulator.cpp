#include "PdRegulator.h"


PdRegulator::PdRegulator(float P, float D)
:p(P),
d(D),
predError(0)
{
  
}


void PdRegulator::toRegulate(float error)
{
  nowTime = millis();
  float reg = error*p+(error-predError)*d/(nowTime-oldTime);
  predError = error;
  oldTime = nowTime;
  force = reg;
}


void PdRegulator::setPredError(float pError)
{
  predError = pError;
}


float PdRegulator::getP()
{
  return p;
}


float PdRegulator::getRegulate()
{
  return force;
}

