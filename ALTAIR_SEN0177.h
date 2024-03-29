
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

#define   SEN0177_READOUT_FLAG_BYTE1   0x42             // The byte containing the first  Serial readout flag for this device.
#define   SEN0177_READOUT_FLAG_BYTE2   0x4d             // The byte containing the second Serial readout flag for this device.
#define   SEN0177_READOUT_INFO_LENGTH    31             // In bytes.  0x42 + 31 bytes is equal to 32 bytes.
#define   SEN0177_NOM_DELAY_BTW_READS     0             // Value is in milliseconds.

#include "Arduino.h"

class ALTAIR_SEN0177 {
  
  public:
  
    ALTAIR_SEN0177(                                 ) ;


    int  transmitPM01(  unsigned char *thebuf       ) ; // Readout PM1.0 value of this airborne dust detector module, in ug/m3.
    int  transmitPM2_5( unsigned char *thebuf       ) ; // Readout PM2.5 value of this airborne dust detector module, in ug/m3.
    int  transmitPM10(  unsigned char *thebuf       ) ; // Readout PM10  value of this airborne dust detector module, in ug/m3.
    void printDustVal(                              ) ;

    void delayBtwReads( int            delay_in_ms =    // Wait between reads  
                        SEN0177_NOM_DELAY_BTW_READS ) ; //   (the nominal wait time is zero!).
    
  private:
  
    int _PM01Value                                    ; // in ug/m3        
    int _PM2_5Value                                   ; // in ug/m3
    int _PM10Value                                    ; // in ug/m3
  
};

#endif
