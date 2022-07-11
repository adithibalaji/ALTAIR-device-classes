#include "ALTAIR_SEN0133.h"


//Constructor with input indicating pin to which sensor is connected
ALTAIR_SEN0133::ALTAIR_SEN0133(int measurePin, int sampleDelay){
 
  measurePin = measurePin; 
  sampleDelay = sampleDelay;
  
}

//Print gas value to serial monitor
void ALTAIR_SEN0133::printGasVal(){

  hydrogenVal = analogRead(measurePin);
  Serial.print("Hydrogen gas value: ");
  Serial.print(hydrogenVal);
  Serial.println("  ppm");
  delay(sampleDelay);
}
