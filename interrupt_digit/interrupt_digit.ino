#include<TM1637Display.h>

#define DIO 11
#define CLK 10
#define touch_sensor 3
#define latch_sensor 2

TM1637Display FND(CLK,DIO);
volatile int touch_sensor_touched = 0;
volatile int latch_sensor_touched = 0;
unsigned int count = 0;

void setup(){
  FND.setBrightness(0x04);
  FND.showNumberDec(count);
  
  pinMode(touch_sensor,INPUT_PULLUP);
  pinMode(latch_sensor,INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(touch_sensor), ISR_INT1, RISING);
  attachInterrupt(digitalPinToInterrupt(latch_sensor), ISR_INT2, CHANGE);
  
  FND.showNumberDec(count);
}

void ISR_INT1()
{
  touch_sensor_touched = 1;
}

void ISR_INT2()
{
  latch_sensor_touched = 1;
}

void loop(){

  if(touch_sensor_touched == 1){
    count+=1;
    FND.showNumberDec(count);
    touch_sensor_touched = 0;
  } 

  if((latch_sensor_touched == 1) && (count>0)){
    count-=1;
    FND.showNumberDec(count);
    latch_sensor_touched = 0;
  } 
}
