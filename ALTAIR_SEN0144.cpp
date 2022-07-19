# include "ALTAIR_SEN0144.h"

#define VCC 5.0
#define INT_VALS 1024.0
#define DENSITY_MULTIPLIER 0.17
#define DENSITY_OFFSET 0.1
#define measurePin 0
#define sampleDelay 1000


//Constructor with input indicating sensor output and LED pin locations
ALTAIR_SEN0144::ALTAIR_SEN0144() {

  voMeasured = calcVoltage = dustDensity = 0;
}



//Drive LED and read raw dust value
void ALTAIR_SEN0144::measureSample(){

  voMeasured = analogRead(measurePin); // read the dust value
  delay(sampleDelay);
}

//Calculate dust density
void ALTAIR_SEN0144::calcDustDensity(){
   // 0 - 5V mapped to 0 - 1023 integer values
  // recover voltage
  calcVoltage = voMeasured * (VCC / INT_VALS);

  // linear eqaution taken from http://www.howmuchsnow.com/arduino/airquality/
  // Chris Nafis (c) 2012
  dustDensity = DENSITY_MULTIPLIER * calcVoltage - DENSITY_OFFSET;
}


//Output dust value
void ALTAIR_SEN0144::printDustVal(){
  measureSample();
  calcDustDensity();
  Serial.print("Dust density: ");
  Serial.print(dustDensity);
  Serial.println("  mg/m3");

}
