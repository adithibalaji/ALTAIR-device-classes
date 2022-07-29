/**************************************************************************/
/*!
    @file     ALTAIR_SEN0177.cpp
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

#include "ALTAIR_SEN0177.h"

//Constructor
ALTAIR_SEN0177::ALTAIR_SEN0177( ) :
  _PM01Value(  0                ) ,
  _PM2_5Value( 0                ) ,
  _PM10Value(  0                )
{
}

// Get PM1.0 value
int ALTAIR_SEN0177::transmitPM01(  unsigned char *thebuf )
{
  _PM01Value  =   ( ( thebuf[3] << 8 ) + thebuf[4]       ) ; // readout PM1.0 value of the airborne dust detector module, in ug/m3
  return         _PM01Value                                ;
}

// Get PM2.5 value
int ALTAIR_SEN0177::transmitPM2_5( unsigned char *thebuf )
{
  _PM2_5Value  =  ( ( thebuf[5] << 8 ) + thebuf[6]       ) ; // readout PM2.5 value of the airborne dust detector module, in ug/m3
  return         _PM2_5Value                               ;
}

// Get PM10 value
int ALTAIR_SEN0177::transmitPM10(  unsigned char *thebuf )
{
  _PM10Value   =  ( ( thebuf[7] << 8 ) + thebuf[8]       ) ; // readout PM10 value of the airborne dust detector module, in ug/m3
  return         _PM10Value                                ;
}

// Run sensor and print dust values to serial monitor
void ALTAIR_SEN0177::printDustVal(                       ) 
{
  unsigned char       buf[ SEN0177_READOUT_INFO_LENGTH   ] ;
  if (   Serial.find(      SEN0177_READOUT_FLAG_BYTE1  ) ) {  // start to read when 0x42 is received over the Serial connection
    Serial.readBytes( buf, SEN0177_READOUT_INFO_LENGTH   ) ;

    if ( buf[0]       ==   SEN0177_READOUT_FLAG_BYTE2    ) {  // check to see if the next byte is 0x4d
      transmitPM01(   buf                                ) ;  // readout PM1.0 value of the airborne dust detector module, in ug/m3
      transmitPM2_5(  buf                                ) ;  // readout PM2.5 value of the airborne dust detector module, in ug/m3
      transmitPM10(   buf                                ) ;  // readout PM10  value of the airborne dust detector module, in ug/m3
    }
  }
      
  Serial.print(  "PM1.0: "                               ) ;
  Serial.print(  _PM01Value                              ) ;
  Serial.println("  ug/m3"                               ) ;

  Serial.print(  "PM2.5: "                               ) ;
  Serial.print(  _PM2_5Value                             ) ;
  Serial.println("  ug/m3"                               ) ;

  Serial.print(  "PM1 0: "                               ) ;
  Serial.print(  _PM10Value                              ) ;
  Serial.println("  ug/m3"                               ) ;
  Serial.println(                                        ) ;
}

void ALTAIR_SEN0177::delayBtwReads( int delay_in_ms      ) {
  delay(                                delay_in_ms      ) ;  
}
