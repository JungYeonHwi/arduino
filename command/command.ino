#include <TM1637Display.h>
#define DIO 11
#define CLK 10
#define LED 3

TM1637Display fnd(CLK, DIO);

String inputString ="";
boolean stringComplete = false;
String number = "";
int num = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED,OUTPUT);

  fnd.setBrightness(1);
  fnd.showNumberDecEx(num);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(stringComplete){
    if((inputString.equals("LED ON")) || (inputString.equals("led on"))){
       Serial.println(inputString);
       digitalWrite(LED, HIGH);
    }
    else if((inputString.equals("LED OFF")) || (inputString.equals("led off"))){
      Serial.println(inputString);
      digitalWrite(LED, LOW);
    }
    else if (inputString[0]=='F' || inputString[0]=='f'){
      number = inputString.substring(4);
      num = number.toInt();
      if (num <= 0000 || num >= 9999){
        Serial.println("Command error");
      }
      else {
        fnd.showNumberDecEx(num);
        Serial.println(inputString);
      }
    }
    else{
      Serial.println("Command error");
    }
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent(){
  while(Serial.available()){
    char inChar = (char)Serial.read(); 
    if (inChar == '\n') {
      stringComplete = true;
    }
    else {
      inputString += inChar;
    }
  }
}
