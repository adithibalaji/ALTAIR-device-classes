/**************************************************************************/
/*!
    @file     ALTAIR_SEN0144.cpp
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

#include "ALTAIR_SEN0144.h"

#define VCC 5.0
#define INT_VALS 1024.0
#define DENSITY_MULTIPLIER 0.17
#define DENSITY_OFFSET 0.1
#define measurePin 0
#define sampleDelay 1000


//Constructor with input indicating sensor output and LED pin locations
ALTAIR_SEN0144::ALTAIR_SEN0144( ) : 
  _voMeasured(  0.              ) ,
  _calcVoltage( 0.              ) ,
  _dustDensity( 0.              )
{
}

//Drive LED and read raw dust value
void ALTAIR_SEN0144::measureSample(    ) {
  _voMeasured = analogRead( measurePin ) ; // read the dust value
}

//Calculate dust density
void ALTAIR_SEN0144::calcDustDensity(  ) {
   // 0 - 5V mapped to 0 - 1023 integer values
  // recover voltage
  _calcVoltage = _voMeasured * (VCC / INT_VALS);

  // linear eqaution taken from http://www.howmuchsnow.com/arduino/airquality/
  // Chris Nafis (c) 2012
  _dustDensity = DENSITY_MULTIPLIER * _calcVoltage - DENSITY_OFFSET;
}


//Output dust value
void ALTAIR_SEN0144::printDustVal(                  ) {
  measureSample(                                    ) ;
  calcDustDensity(                                  ) ;
  Serial.print("Dust density: "                     ) ;
  Serial.print(_dustDensity                         ) ;
  Serial.println("  mg/m3"                          ) ;
}

void ALTAIR_SEN0144::delayBtwReads( int delay_in_ms ) {
  delay(         delay_in_ms                        ) ;  
}
