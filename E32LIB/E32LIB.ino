#include "Arduino.h"
#include "e32433t30d.h"

#define TX
//#define RX

HardwareSerial uart2(2);

E32 myE32(&uart2, _19200, _9P6 , 16, 17, 2, 4, 5);

void setup (){
  Serial.begin(115200);
  myE32.init();
  uint8_t param[6];
  myE32.getParam(param);
  myE32.showParam(param);
  
}

void loop(){

  #ifdef TX
  myE32.sendTo(0x0B, 0xDD, 0xCC, "hello\n",  6);
  delay(100);
  #endif
  if(myE32.available()){
    Serial.print((char)myE32.getData());
  }

}