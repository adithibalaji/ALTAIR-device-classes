

#include <ALTAIR_SEN0133.h>
#include <ALTAIR_SEN0144.h>
#include <ALTAIR_SEN0177.h>
#include <ALTAIR_HCSR04.h>


//ALTAIR_SEN0133 sen0133;
//ALTAIR_SEN0144 sen0144;
//ALTAIR_SEN0177 sen0177;
  ALTAIR_HCSR04 hcsr04; 

void setup() {
  //Initialize serial baud rate
  Serial.begin(38400);
}

void loop() {
//Test sensor output here
//sen0133.delayBtwReads; sen0133.printHydrogenGasVal();
//sen0144.delayBtwReads; sen0144.printDustVal();
//sen0177.delayBtwReads; sen0177.printDustVal();
hcsr04.delayBtwPings(); hcsr04.printDistance();
}
