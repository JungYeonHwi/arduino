#include<TM1637Display.h>
#define DIO 11
#define CLK 10
#define FULL_ANGLE 280
#define MAX_ADC 1023
#define TOUCH 3

char buf[80];
TM1637Display FND(CLK,DIO);

volatile int touched = 0;
unsigned int count = 0;
int analogPin = 5;
int degree = 0;
int adValue;

void setup() {
 // put your setup code here, to run once:
 FND.setBrightness(0x04);
 FND.showNumberDec(degree);
 pinMode(TOUCH, INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(TOUCH),ISRF,CHANGE);
 FND.showNumberDec(degree);
}

void ISRF() {
 touched = 1;
}

void loop() {
 // put your main code here, to run repeatedly:
 if(touched == 1) {
 adValue = analogRead(analogPin);

 degree = (int)((float)adValue * FULL_ANGLE / MAX_ADC);

 FND.showNumberDec(degree);

 sprintf(buf, "degree : %d", degree);
 Serial.println(buf);
 touched = 0;
 }
}
