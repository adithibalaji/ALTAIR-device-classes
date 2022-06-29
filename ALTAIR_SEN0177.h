#ifndef   ALTAIR_SEN0177_h
#define   ALTAIR_SEN0177_h

#include "Arduino.h"
#define LENG 31   //0x42 + 31 bytes equal to 32 bytes
;

/*
 * Class for DFrobot SEN 0177 Dust sensor, adapted from wiki code on website
 */
class ALTAIR_SEN0177 {
  
  public:
  
  ALTAIR_SEN0177();

  int PM01Value=0;          
  int PM2_5Value=0;         
  int PM10Value=0;   

  int transmitPM01(unsigned char *thebuf);
  int transmitPM2_5(unsigned char *thebuf);
  int transmitPM10(unsigned char *thebuf);
  void printDustVal();
    
};

#endif
