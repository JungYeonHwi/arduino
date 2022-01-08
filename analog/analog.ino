int analogPin = 5;
int ledPin = 10;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin);
  analogWrite(ledPin, val>>2);
  delay(1000);
}
