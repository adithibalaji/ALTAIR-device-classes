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

#define HCSR04_MAX_DISTANCE        350       // cm
#define SPEED_OF_SOUND               0.0343  // cm per us
#define HCSR04_NOM_ECHO_PIN          3
#define HCSR04_NOM_TRIG_PIN          2
#define HCSR04_NOM_DELAY_BTW_PINGS  50       // ms
#define HCSR04_MIN_DELAY_BTW_PINGS  29       // ms

#include "Arduino.h"
#include <NewPing.h>

class ALTAIR_HCSR04{
  public:

    ALTAIR_HCSR04(              ) ;  // Uses default echo pin and trigger pin values HCSR04_NOM_ECHO_PIN and HCSR04_NOM_TRIG_PIN defined above.
    ALTAIR_HCSR04( byte echoPin ,
                   byte trigPin ) ;  // Uses user-supplied echo pin and trigger pin values.

    float     getDistance(      ) ;  // Returned distance is in cm, and will be 0 when the actual distance exceeds MAX_HCSR04_DISTANCE.
                                     // When running this repeatedly for a single HCSR04, please ensure that you
                                     //   have an  hcsr04.delayBtwPings();  between each such request.

    void      printDistance(    ) ;  // When running this repeatedly for a single HCSR04, please ensure that you
                                     //   have an  hcsr04.delayBtwPings();  between each such request.

    void      delayBtwPings( int delay_in_ms =               // Wait 50 ms between pings (about 20 pings/sec).  Note that
                             HCSR04_NOM_DELAY_BTW_PINGS ) ;  //   the shortest possible delay between pings should be 29 ms.

  private:

    NewPing  _sonar               ;

};

#endif
