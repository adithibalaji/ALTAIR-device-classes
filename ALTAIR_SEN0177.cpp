#include "ALTAIR_SEN0177.h"


//Constructor
ALTAIR_SEN0177::ALTAIR_SEN0177(){
  
  int PM01Value = 0;
  int PM2_5ValuE = 0;
  int PM10Value = 0;


}
//Get PM1.0 value
int ALTAIR_SEN0177::transmitPM01(unsigned char *thebuf)
{
  int PM01Val;
  PM01Val=((thebuf[3]<<8) + thebuf[4]); //count PM1.0 value of the air detector module
  return PM01Val;
}

//Get PM2.5 value
int ALTAIR_SEN0177::transmitPM2_5(unsigned char *thebuf)
{
  int PM2_5Val;
  PM2_5Val=((thebuf[5]<<8) + thebuf[6]);//count PM2.5 value of the air detector module
  return PM2_5Val;
  }

//Get PM10 value
int ALTAIR_SEN0177::transmitPM10(unsigned char *thebuf){
  int PM10Val;
  PM10Val=((thebuf[7]<<8) + thebuf[8]);//count PM10 value of the air detector module
  return PM10Val;
  }

//Run sensor and print dust values to serial monitor
void ALTAIR_SEN0177::printDustVal(){

    unsigned char buf[LENG];
    if(Serial.find(0x42)){    //start to read when detect 0x42
    Serial.readBytes(buf,LENG);

    if(buf[0] == 0x4d){
        PM01Value=transmitPM01(buf); //count PM1.0 value of the air detector module
        PM2_5Value=transmitPM2_5(buf);//count PM2.5 value of the air detector module
        PM10Value=transmitPM10(buf); //count PM10 value of the air detector module
    }
   }
      Serial.print("PM1.0: ");
      Serial.print(PM01Value);
      Serial.println("  ug/m3");

      Serial.print("PM2.5: ");
      Serial.print(PM2_5Value);
      Serial.println("  ug/m3");

      Serial.print("PM1 0: ");
      Serial.print(PM10Value);
      Serial.println("  ug/m3");
      Serial.println();
}
