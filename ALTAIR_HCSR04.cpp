/**************************************************************************/
/*!
    @file     ALTAIR_HCSR04.cpp
    @author   Adithi Balaji (adithibalaji@uvic.ca)
    @license  GPL
    
    This is the class for the three ALTAIR HCSR04 ultrasonic distance  
    sensors, located at the bottom of the gondola (two in the bottom rear 
    corners, one on bottom front centre), used during landing to see how
    close the ground is (and then to use propulsion to slow the descent, 
    and attempt to ensure a nice soft landing with the bottom of the 
    gondola oriented at the same slope as the ground).
    
    Adithi Balaji  adithibalaji@uvic.ca  began in June 2022
    Justin Albert  jalbert@uvic.ca       updated on 27 July 2022
    
    @section  HISTORY
    v1.0  - First version
*/
/**************************************************************************/

#include "ALTAIR_HCSR04.h"


ALTAIR_HCSR04::ALTAIR_HCSR04(                                             ) :   
    _sonar( HCSR04_NOM_TRIG_PIN, HCSR04_NOM_ECHO_PIN, MAX_HCSR04_DISTANCE ) 
{
}

ALTAIR_HCSR04::ALTAIR_HCSR04( byte echoPin , byte trigPin                 ) :   
    _sonar(             trigPin,             echoPin, MAX_HCSR04_DISTANCE ) 
{
}

float ALTAIR_HCSR04::getDistance(          ) {
    float      duration      = _sonar.ping() ;
    return    (duration / 2) * SPEED_OF_SOUND;
}
  
void  ALTAIR_HCSR04::delayBtwPings( int delay_in_ms ) {
        delay( delay_in_ms                          ) ; // Wait 50 ms between pings (about 20 pings/sec). 
}                                                       //   29 ms should be the shortest possible delay between pings.

void  ALTAIR_HCSR04::printDistance() {    
    Serial.print(  "Distance = "   );
    Serial.print(getDistance(     ));    
    Serial.println(" cm"           );
}

