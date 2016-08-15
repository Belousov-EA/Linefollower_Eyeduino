#ifndef PD_REGULATOR
#define PD_REGULATOR

#include <Arduino.h>

class PdRegulator
{
  public:
    PdRegulator(float P, float D);
    void toRegulate(float error);
    void setPredError(float pError);
    float getP();
    float getRegulate();
  protected:
    float p;
    float d;
  private:
    float force;    
    float predError;
    unsigned long oldTime;
    unsigned long nowTime;
};

#endif
