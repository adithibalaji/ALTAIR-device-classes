#ifndef   ALTAIR_SEN0133_h
#define   ALTAIR_SEN0133_h

#include "Arduino.h"

class ALTAIR_SEN0133 {
  
  public:
  
  ALTAIR_SEN0133(int measurePin);

  int measurePin;
  int sampleDelay;
  int hydrogenVal;


  void printGasVal(hydrogenVal);
}

#endif
