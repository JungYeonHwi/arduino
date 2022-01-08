#include <SoftwareSerial.h>

#include <TimerOne.h>

#define LED 10
uint8_t ledState = LOW;
uint8_t tSec = 0;
long tperiod;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(LED, OUTPUT);
  tPeriod = 1000000;
  Timer1.initialize(1000000); // 1sec
  Timer1.pwm(LED, 511);
  Timer1.attachInterrupt(blinked); // ISR
}

void blinked() {
  tSec = tSec + 1;
  if (tSec == 10) {
    if (tPeriod > 1000) {
      tPeriod = tPeriod / 10;
      Timer1.setPeriod(tPeriod);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
