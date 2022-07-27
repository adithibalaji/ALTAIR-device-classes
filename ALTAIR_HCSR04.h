/**************************************************************************/
/*!
    @file     ALTAIR_HCSR04.h
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

#ifndef ALTAIR_HCSR04_h
#define ALTAIR_HCSR04_h

#define MAX_HCSR04_DISTANCE        350       // cm
#define SPEED_OF_SOUND               0.0343  // cm per us
#define HCSR04_NOM_ECHO_PIN          3
#define HCSR04_NOM_TRIG_PIN          2
#define HCSR04_MIN_DELAY_BTW_PINGS  50       // ms

#include "Arduino.h"
#include <Newping.h>

class ALTAIR_HCSR04{
  public:

    ALTAIR_HCSR04(              ) ;  // Uses default echo pin and trigger pin values HCSR04_NOM_ECHO_PIN and HCSR04_NOM_TRIG_PIN defined above.
    ALTAIR_HCSR04( byte echoPin , 
                   byte trigPin ) ;  // Uses user-supplied echo pin and trigger pin values.

    float     getDistance(      ) ;  // Returned distance is in cm, and will be 0 when the actual distance exceeds MAX_HCSR04_DISTANCE.
                                     // When running this repeatedly for a single HCSR04, please ensure that you
                                     //   have a delay(HCSR04_MIN_DELAY_BTW_PINGS); between each such request.
    void      printDistance(    ) ;
  
  private:
  
    NewPing  _sonar               ;

};

#endif
