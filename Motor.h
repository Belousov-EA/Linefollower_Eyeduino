//23.07.2016
#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

 class Motor
 {
    public:
      Motor(int pPin, int dPin);
      void init();
      void setPower(int  power, bool direction);
    private:
      const int powerPin;
      const int directionPin;
 };
#endif
