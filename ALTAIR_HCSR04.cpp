#include "ALTAIR_HCSR04.h"


ALTAIR_HCSR04::ALTAIR_HCSR04(      ) :   
    _sonar( HCSR04_TRIG_PIN, HCSR04_ECHO_PIN, MAX_HCSR04_DISTANCE ) 
{
}

float ALTAIR_HCSR04::getDistance(  ) {
    float      duration      = _sonar.ping();
    return    (duration / 2) * SPEED_OF_SOUND;
  
    delay(     HCSR04_MIN_DELAY_BTW_PINGS);
}
  
void  ALTAIR_HCSR04::printDistance() {
    delay(50);                        // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  
    Serial.print("Distance = ");
    Serial.print(getDistance());           // Distance will be 0 when out of set max range.
    Serial.println(" cm");
}

