#include "ALTAIR_HCSR04.h"

#define MAX_DISTANCE 350
#define SPEED_OF_SOUND 0.0343
#define echoPin 3
#define trigPin 2

ALTAIR_HCSR04::ALTAIR_HCSR04(){   
float duration;
float distance;
}

void ALTAIR_HCSR04::printDistance(){
delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
NewPing sonar(trigPin, echoPin, MAX_DISTANCE);
duration = sonar.ping();
distance = (duration / 2) * SPEED_OF_SOUND;
  
Serial.print("Distance = ");
Serial.print(distance); // Distance will be 0 when out of set max range.
Serial.println(" cm");
}

