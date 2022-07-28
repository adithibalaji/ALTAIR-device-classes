/**************************************************************************/
/*!
    @file     ALTAIR_SEN0133.cpp
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

#include "ALTAIR_SEN0133.h"

// Default constructor
ALTAIR_SEN0133::ALTAIR_SEN0133(                 ) {
  _readoutPin  = SEN0133_NOM_READOUT_PIN          ;
}

// Constructor with input indicating pin to which sensor is connected
ALTAIR_SEN0133::ALTAIR_SEN0133( byte readoutPin ) {
  _readoutPin  = readoutPin                       ;
}

// The returned value is in ppm.
int  ALTAIR_SEN0133::getGasVal(                 ) {
  _hydrogenVal = analogRead(        _readoutPin ) ;
  return        _hydrogenVal                      ;
}

// Print gas value to serial monitor
void ALTAIR_SEN0133::printGasVal(               ) {
  Serial.print("Hydrogen gas value: "           ) ;
  Serial.print( getGasVal( )                    ) ;
  Serial.println("  ppm"                        ) ;
}
