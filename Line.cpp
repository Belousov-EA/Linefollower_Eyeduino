#include "Line.h"

Line::Line(int _sensorCount, int _sensors[], int _weight[], int _white[], int _black[])
:Sensor(_sensorCount, _sensors)
{
  weight = new int [sensorCount];
  white = new int [sensorCount];
  black = new int [sensorCount];
  znachenieSensor = new int [sensorCount];
  linePro = new float [sensorCount];
  
  for (int i=0; i<sensorCount; i++)  
  {
    weight[i] = _weight[i];
    white[i]=_white[i];
    black[i]=_black[i];
  }
}


void Line::call()
{
    dark = 0;
    value = 0;
    readSensors();
    calk();
}

float Line::getDark()
{
  return dark;
}

void Line::readSensors()
{
  for (int i = 0; i<sensorCount; i++)
  {
    znachenieSensor[i]=analogRead(pins[i]);
  }
}



void Line::calk()
{
  int perehod = 0;

  for (int i = 0; i<sensorCount; i++)
  {
    if (znachenieSensor[i]>black[i])
    {
      linePro[i] = 1;
    }else if(znachenieSensor[i]<white[i])
    {
      linePro[i] = 0;
    }else
    {
      linePro[i]=float(znachenieSensor[i]-white[i])/float(black[i]-white[i]);
      linePro[i]=constrain(linePro[i],0,1);
    }
  }


  for (int i = 0; i<sensorCount; i++)
  {
    value+=weight[i]*linePro[i];
    dark+=linePro[i];
    if(i>0)
    {
      if(abs(linePro[i]-linePro[i-1])>0.7)
      {
        perehod++;
      }
    }
  }


  if ((dark>0)&&(perehod<3))
  {
    value/=(dark*sensorCount/2);
  }else
  {
    value=0;
  }
  
#ifdef SORT_TREK
  if (dark>3)
  {
    value = 0;
  }
#endif
 
}




