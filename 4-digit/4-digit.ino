#include <TH1637Display.h>

#define DIO 11
#define CLK 10
#define FULL_ANGLE 
#define MAX_ADC 1023.0

TM1637Display FND(CLK, DIO);
int adValue;
int degree;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  degree = 0;
  FDN.setBrightness(0x04);
  FND.showNumberDec(degree);
}

void loop() {
  // put your main code here, to run repeatedly:
  adValue = analogRead(analogPin);
  Serial.println(adValue);

  degree = (int)((float)adValue * FULL_ANGLE / MAX_ADC);
  FND.showNumberDec(degree);

  delay(1000);
}
