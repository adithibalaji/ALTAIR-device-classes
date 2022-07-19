#ifndef   ALTAIR_SEN0144_h
#define   ALTAIR_SEN0144_h

#include "Arduino.h"

/*Class for Sharp Optical Dust Sensor GP2Y1010AU0F, adapted from sample code on DFRobot website
 * 
 */
class ALTAIR_SEN0144 {
  
  public:
  
  ALTAIR_SEN0144(int measurePin, int sampleDelay);

  int measurePin;
  int sampleDelay; 

  float voMeasured;
  float calcVoltage;
  float dustDensity;


  void measureSample();
  void calcDustDensity();
  void printDustVal();
\
    
};

#endif
