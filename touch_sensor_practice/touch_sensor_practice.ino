#define TOUCH 11
#define BAUDRATE 115200
#define LED 3

uint8_t prevTouch=0;
uint8_t currTouch=0;

void  setup() {
//  put your  setup code  here, to  run once:
pinMode(TOUCH,INPUT);
pinMode(LED,OUTPUT);

Serial.begin(BAUDRATE);
Serial.println("Reday");

}
void  loop()  {
//  put your  main  code  here, to  run repeatedly:
  currTouch=digitalRead(TOUCH);
  
  if((prevTouch==LOW)&&(currTouch==HIGH)){ 
   Serial.println("ON");
   digitalWrite(LED,HIGH); 
  }
  
  if((prevTouch==HIGH)&&(currTouch==LOW)) {
   Serial.println("OFF");
   digitalWrite(LED,LOW); 
  }
  
  prevTouch=currTouch;
}
