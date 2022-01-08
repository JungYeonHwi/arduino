#include <TimerOne.h>
#define LED 13

int flag = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Timer1.initialize(100000);
  Timer1.attachInterrupt(blinked);
}

void blinked() {
  
  flag = (flag+1)%10;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (flag <= 2) {
    digitalWrite(LED, HIGH);
  }

  else digitalWrite(LED, LOW);

}
