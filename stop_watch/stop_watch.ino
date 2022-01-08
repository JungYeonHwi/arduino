#include <TM1637Display.h>
#include <TimerOne.h>

#define TOUCH 3
#define DIO 11
#define CLK 10

volatile int touched = 0;

TM1637Display fnd(CLK, DIO);
volatile uint8_t tSec = 0;
volatile uint8_t tMin = 0;
volatile uint8_t tFlag = 0;
volatile uint8_t tFlag1 = 0;
volatile long tPeriod = 50000; // 0.05초 주기

uint16_t num;
uint16_t dot;

void setup() {
  // put your setup code here, to run once:
  pinMode(TOUCH, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(TOUCH),ISRF,RISING);

  Timer1.initialize(tPeriod);
  Timer1.attachInterrupt(blinked);
  
  fnd.setBrightness(1);
  fnd.showNumberDecEx(num, dot, true);
}

void ISRF() {
  touched += 1;
}

void blinked() { // 0.05초마다 실행
    if (touched % 2 == 1) {
      tSec = tSec + 5;
      if (tSec == 100) { // 1초마다 실행되는 경우
        tMin += 1;
        tSec = 0;
      }

      if (tSec == 50) { // 0.5초마다 실행되는 경우
        tFlag1 ^= 1;
      }
      tFlag = 1;
    }

    if (touched % 2 == 0) {
      tSec = 0;
      tMin = 0;
    }
}

void loop() {
  // put your main code here, to run repeatedly:

    if (tFlag == 1) {
      num = tMin * 100 + tSec;
      dot = (tFlag1 % 2 == 0) ? 0 : 0x40;
      fnd.showNumberDecEx(num, dot, true);
    }

    tFlag = 0;
}
