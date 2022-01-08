const byte ledPin = 10;
const byte interruptPin = 3;
volatile byte state = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  

}

void blink() {
  state = state ^ 1; // !:logical NOT, ^: xor
  digitalWrite(ledPin, state);
}
