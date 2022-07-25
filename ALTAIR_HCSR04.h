#ifndef ALTAIR_HCSR04_h
#define ALTAIR_HCSR04_h

#include "Arduino.h"
#include <Newping.h>

class ALTAIR_HCSR04{
  public:

    ALTAIR_HCSR04(      )               ;

    float duration(     ) { return _dura; }
    float distance(     ) { return _dist; }

    void  printDistance()               ;
  
  private:
  
    float _dura                         ;
    float _dist                         ;

};

#endif
