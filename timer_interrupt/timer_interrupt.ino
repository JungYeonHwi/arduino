#include <TimerOne.h>

#define LED 13
uint8_t ledState = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
  Timer1.initialize(500000); // 0.5sec
  Timer1.attachInterrupt(blinked); // ISR
}

void blinked() {
  ledState ^= 1;
  digitalWrite(LED, ledState);
}

void loop() {
  // put your main code here, to run repeatedly:

}
