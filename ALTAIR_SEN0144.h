/**************************************************************************/
/*!
    @file     ALTAIR_SEN0144.h
    @author   Adithi Balaji (adithibalaji@uvic.ca)
    @license  GPL
    
    This is the class for the ALTAIR SEN0144 dust sensor, which contains
    the Sharp Optical Dust Sensor GP2Y1010AU0F.  This sensor is not by
    default located onboard ALTAIR (yet), but perhaps will be mounted 
    onboard ALTAIR (in at least some flight configurations) sometime in
    the future.  Since the SEN0144 is a DFRobot product, this code is 
    adapted from sample code on the DFRobot website.
    
    Adithi Balaji  adithibalaji@uvic.ca  began in June 2022
    Justin Albert  jalbert@uvic.ca       updated on 28 July 2022
    
    @section  HISTORY
    v1.0  - First version
*/
/**************************************************************************/

#ifndef   ALTAIR_SEN0144_h
#define   ALTAIR_SEN0144_h

#define   SEN0144_NOM_READOUT_PIN        A0                  // Analog 0 is the nominal readout pin.
#define   SEN0144_NOM_DELAY_BTW_READS  1000                  // Value is in milliseconds.
#define   SEN0144_NOM_VCC                 5.0                // Value is in volts/VCC.
#define   SEN0144_INT_VALS             1024                  // Value is in ADUs/VCC.
#define   SEN0144_DENSITY_MULTIPLIER      0.17               // Value is in mg/(volt x m3).
#define   SEN0144_DENSITY_OFFSET          0.1                // Value is in mg/m3.

#include "Arduino.h"

class ALTAIR_SEN0144 {
  
  public:
  
    ALTAIR_SEN0144(                                      ) ;
    ALTAIR_SEN0144(          byte  readoutPin            ) ;

    void   measureSample(                                ) ;
    void   calcDustDensity(                              ) ; // in mg/m3
    void   printDustVal(                                 ) ;
    
    void   delayBtwReads(    int   delay_in_ms =             // Wait between reads  
                             SEN0144_NOM_DELAY_BTW_READS ) ; //   (the nominal wait time is 1 second).
  
  private:
  
    byte  _readoutPin                                      ;
    float _voMeasured                                      ; // in ADUs
    float _calcVoltage                                     ; // in volts
    float _dustDensity                                     ; // in mg/m3
  
};

#endif
