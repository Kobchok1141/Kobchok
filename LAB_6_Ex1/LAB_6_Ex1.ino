#include <ThreeWire.h>
#include <RtcDS1302.h>

ThreeWire myWire(4,5,2);
RtcDS1302<ThreeWire>Rtc(myWire);

#define LED 7

void setup(){
  
  Rtc.Begin();
  pinMode(LED, OUTPUT);
  
}

void loop(){
  
  RtcDateTime now = Rtc.GetDateTime();

  if((now.Second()%2)==0){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
  
  delay(500);
}
