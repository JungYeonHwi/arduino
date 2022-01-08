int analogPin = 5;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin);
  Serial.println(val);
  delay(200);
}
