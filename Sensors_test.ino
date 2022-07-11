
#include <ALTAIR_SEN0133.h>
#include <ALTAIR_SEN0144.h>
#include <ALTAIR_SEN0177.h>

//ALTAIR_SEN0133 sen0133(0,1000);
//ALTAIR_SEN0144 sen0144(0,2);
ALTAIR_SEN0177 sen0177;

void setup() {
  //No setup required for sensors. If they are functioning, there should be output to the serial monitor
}

void loop() {
  //Test sensor output here
//  sen0133.printGasVal();
//  sen0144.measureSample(280,40);
  sen0177.printDustVal();
}
