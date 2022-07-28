/**************************************************************************/
/*!
    @file     ALTAIR_SEN0133.h
    @author   Adithi Balaji (adithibalaji@uvic.ca)
    @license  GPL
    
    This is the class for the ALTAIR SEN0133 hydrogen gas sensor, which is
    not by default located onboard ALTAIR (yet), but perhaps will be  
    mounted onboard ALTAIR (in at least some flight configurations) 
    sometime in the future.
    
    Adithi Balaji  adithibalaji@uvic.ca  began in June 2022
    Justin Albert  jalbert@uvic.ca       updated on 28 July 2022
    
    @section  HISTORY
    v1.0  - First version
*/
/**************************************************************************/

#ifndef   ALTAIR_SEN0133_h
#define   ALTAIR_SEN0133_h

#define   SEN0133_NOM_READOUT_PIN        A0                  // Analog 0 is the nominal readout pin.
#define   SEN0133_NOM_DELAY_BTW_READS  1000                  // Value is in milliseconds.

#include "Arduino.h"

class ALTAIR_SEN0133 {
  
  public:

    ALTAIR_SEN0133(                                      ) ;
    ALTAIR_SEN0133(          byte  readoutPin            ) ;
    
    int   getHydrogenGasVal(                             ) ; // Returned value is in ppm.
    void  printHydrogenGasVal(                           ) ;
    
    void  delayBtwReads(     int   delay_in_ms =             // Wait between reads  
                             SEN0133_NOM_DELAY_BTW_READS ) ; //   (the nominal wait time is 1 second).

  private:
    byte _readoutPin                                       ;
    int  _hydrogenVal                                      ; // Value is in ppm.

};

#endif
