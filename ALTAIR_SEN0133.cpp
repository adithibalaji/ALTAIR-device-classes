#include "ALTAIR_SEN0133.h"
#define measurePin 0
#define sampleDelay 1000

//Constructor with input indicating pin to which sensor is connected
ALTAIR_SEN0133::ALTAIR_SEN0133(){
  
}

//Print gas value to serial monitor
void ALTAIR_SEN0133::printGasVal(){

  hydrogenVal = analogRead(measurePin);
  Serial.print("Hydrogen gas value: ");
  Serial.print(hydrogenVal);
  Serial.println("  ppm");
  delay(sampleDelay);
}
