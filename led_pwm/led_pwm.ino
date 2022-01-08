#define LED 13

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Timer1.initialize(1000000);
  Timer1.pwm(LED,1024*0.3); 
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
