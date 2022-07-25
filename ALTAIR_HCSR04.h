#ifndef ALTAIR_HCSR04_h
#define ALTAIR_HCSR04_h

#define MAX_HCSR04_DISTANCE        350       // cm
#define SPEED_OF_SOUND               0.0343  // cm per us
#define HCSR04_ECHO_PIN              3
#define HCSR04_TRIG_PIN              2
#define HCSR04_MIN_DELAY_BTW_PINGS  50       // ms

#include "Arduino.h"
#include <Newping.h>

class ALTAIR_HCSR04{
  public:

    ALTAIR_HCSR04(      ) ;

    float getdistance(  ) ;

    void  printDistance() ;
  
  private:
  
    NewPing _sonar        ;

};

#endif
