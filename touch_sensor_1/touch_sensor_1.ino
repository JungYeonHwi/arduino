#define TOUCH 11
#define BAUDRATE 115200
#define LED 3

uint8_t prevTouch=0;
uint8_t currTouch=0;
uint8_t chk = 1;

void  setup() {
//  put your  setup code  here, to  run once:
  pinMode(TOUCH,INPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(BAUDRATE);
  Serial.println("Ready");

}
void  loop()  {
//  put your  main  code  here, to  run repeatedly:
  currTouch=digitalRead(TOUCH);

  if((prevTouch==LOW)&&(currTouch==HIGH)) { 
  
   if (chk == 1) {
    digitalWrite(LED,HIGH); 
    Serial.println("ON");
    chk = 0;
   }

   else {
    digitalWrite(LED,LOW);
    Serial.println("OFF");
    chk = 1;
   }
  }

  prevTouch=currTouch;
}
