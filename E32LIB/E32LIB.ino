#include "Arduino.h"
#include "e32433t30d.h"

HardwareSerial uart2(2);

E32 myE32(&uart2, _19200, 16, 17, 2, 4, 5);

void setup (){
  Serial.begin(115200);
  Serial.println("hello");
  myE32.init();
  uint8_t param[6];
  myE32.getParam(param);
  myE32.showParam(param);
  
}

void loop(){
  if(myE32.available()){
    Serial.println(myE32.getData(),HEX);
  }
}