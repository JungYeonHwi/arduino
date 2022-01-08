#include <SimpleTimer.h>
#define SENSOR 5
#define LED 3

int adValue;

SimpleTimer firstTimer(1000); 
     
void setup() {
 pinMode(LED, OUTPUT);
}

void loop() {
 if (firstTimer.isReady())  {
  adValue=analogRead(SENSOR);
  adValue=255-(adValue/4);
  analogWrite(LED,adValue);
  }
}
