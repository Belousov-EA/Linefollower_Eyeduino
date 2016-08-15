#include "Camera.h"

Camera::Camera()
:Sensor(0, NULL)
{
  
}

void Camera::init()
{
  Serial1.begin(115200);
}

void Camera::call()
{
  if(Serial1.available()!= 0)
  {
    char read = Serial1.read();
    value = constrain(abs(float(int(read)-128)/128), 0, 1);
  }
}

