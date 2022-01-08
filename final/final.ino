#include <TM1637Display.h>
#include "OneWire.h"
#include <TimerOne.h>

#define DIO 6
#define CLK 5
#define TOUCH 3
#define LED 9
OneWire ds(11);

TM1637Display FND(CLK,DIO);

volatile uint16_t touched = 0;
volatile uint16_t touchedTime = 0;
volatile long tPeriod = 10000; // 0.01초
volatile uint16_t check = 0;
volatile uint16_t mill = 0;
int ledState = LOW;

byte ds_addr[8]; // DS18B20 ID
uint8_t found; // set if DS18B20 is found
uint8_t scratchpad[10]; // read buffer for scratchpad
int16_t raw; // raw data
float celcius;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  
  Timer1.initialize(tPeriod);
  Timer1.attachInterrupt(TIMER_FUN);
  
  attachInterrupt(digitalPinToInterrupt(TOUCH), ISR_FUN, CHANGE);
  
  FND.setBrightness(1);
  found = ds.search(ds_addr); // 디바이스 찾기
}

void TIMER_FUN(){
  if(touched == 1)  { // touch 하는 경우
    mill += 1;
  }
}

void ISR_FUN(){
  touched ^= 1; // touch할 때마다 값 변경
 
  if(touched == 0)  { // touch 전->후 사이의 시간을 측정하기 위함
    touchedTime = mill; // 전->후 사이 시간 저장
    mill = 0;
    check = 1;
  }
}

void loop() {
  if((check == 1) && (touchedTime < 100)) { // touch 전->후 사이의 시간이 0.01초 미만이면
    ledState ^= 1;
    digitalWrite(LED,ledState); // led 상태를 바꿈
    
    touchedTime = 0;
    check = 0;
  }
  
  else if((check == 1) && (touchedTime >= 100)) { // touch 전->후 사이의 시간이 0.01초 이상이면
    if (found) { // 디바이스가 있다면
      ds.reset();
      ds.select(ds_addr);
      ds.write(0x44, 1);
      ds.reset();
      ds.select(ds_addr);
      ds.write(0xBE);
      ds.read_bytes(scratchpad, 9);
      raw = ((int16_t)scratchpad[1] << 8) + (int16_t)scratchpad[0];
      celcius = (float)raw/16.0; // 온도
    
      FND.showNumberDecEx(celcius*100, 0x40, true); // 온도를 FND에 출력하기 위해서 celcius*100
    }
    check = 0;
    touchedTime = 0;
  }
}
