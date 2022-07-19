#ifndef ALTAIR_HCSR04_h
#define ALTAIR_HCSR04_h

#include "Arduino.h"
#include <Newping.h>

class ALTAIR_HCSR04{
public:

ALTAIR_HCSR04();
float duration;
float distance;



void printDistance();

};

#endif