#include "ALTAIR_SEN1033.h"


//Constructor with input indicating pin to which sensor is connected
ALTAIR_SEN0133::ALTAIR_SEN1033(int measurePin, int sampleDelay){
 
  _measurePin = measurePin; 
  _sampleDelay = sampleDelay;
}

//Print gas value to serial monitor
void ALTAIR_SEN0133::printGasVal(int sampleDelay){
  hydrogenVal = analogRead(measurePin);
  Serial.print("Hydrogen gas value: ");
  Serial.print(hydrogenVal);
  Serial.println("  ppm");
  delay(sampleDelay);
}
