#include "ALTAIR_HCSR04.h"


ALTAIR_HCSR04::ALTAIR_HCSR04(                                     ) :   
    _sonar( HCSR04_TRIG_PIN, HCSR04_ECHO_PIN, MAX_HCSR04_DISTANCE ) 
{
}

float ALTAIR_HCSR04::getDistance(          ) {
    delay(     HCSR04_MIN_DELAY_BTW_PINGS  ) ; // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    
    float      duration      = _sonar.ping() ;
    return    (duration / 2) * SPEED_OF_SOUND;
}
  
void  ALTAIR_HCSR04::printDistance() {
    Serial.print(  "Distance = "   );
    Serial.print(getDistance(     ));    
    Serial.println(" cm"           );
}

