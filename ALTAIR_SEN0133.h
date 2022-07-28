/**************************************************************************/
/*!
    @file     ALTAIR_SEN0133.h
    @author   Adithi Balaji (adithibalaji@uvic.ca)
    @license  GPL
    
    This is the class for the ALTAIR SEN0133 hydrogen gas sensor, which is
    not by default located onboard ALTAIR (yet), but perhaps will be  
    mounted onboard ALTAIR (in at least some flight configurations) 
    sometime in the future.
    
    Adithi Balaji  adithibalaji@uvic.ca  began in June 2022
    Justin Albert  jalbert@uvic.ca       updated on 28 July 2022
    
    @section  HISTORY
    v1.0  - First version
*/
/**************************************************************************/

#ifndef   ALTAIR_SEN0133_h
#define   ALTAIR_SEN0133_h

#include "Arduino.h"

class ALTAIR_SEN0133 {
  
  public:
    ALTAIR_SEN0133(  );

    int  getGasVal(  );
    void printGasVal();
  
  private:
    int _hydrogenVal  ;

};

#endif
