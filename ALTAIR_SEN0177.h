
/**************************************************************************/
/*!
    @file     ALTAIR_SEN0177.h
    @author   Adithi Balaji (adithibalaji@uvic.ca)
    @license  GPL
    
    This is the class for the ALTAIR SEN0177 dust sensor.  This sensor is 
    not by default located onboard ALTAIR (yet), but perhaps will be 
    mounted onboard ALTAIR (in at least some flight configurations)
    sometime in the future.  Since the SEN0177 is a DFRobot product, this
    code is adapted from sample code on the DFRobot website.
    
    Adithi Balaji  adithibalaji@uvic.ca  began in June 2022
    Justin Albert  jalbert@uvic.ca       updated on 28 July 2022
    
    @section  HISTORY
    v1.0  - First version
*/
/**************************************************************************/

#ifndef   ALTAIR_SEN0177_h
#define   ALTAIR_SEN0177_h

#define   LENG 31   //0x42 + 31 bytes equal to 32 bytes

#include "Arduino.h"

class ALTAIR_SEN0177 {
  
  public:
  
    ALTAIR_SEN0177(                           ) ;


    int  transmitPM01(  unsigned char *thebuf ) ;
    int  transmitPM2_5( unsigned char *thebuf ) ;
    int  transmitPM10(  unsigned char *thebuf ) ;
    void printDustVal(                        ) ;

  private:
  
    int _PM01Value                              ;          
    int _PM2_5Value                             ;         
    int _PM10Value                              ;     
  
};

#endif
