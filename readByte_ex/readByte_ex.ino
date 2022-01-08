char incomingByte = 0;
char buf[80];
char outBuf[80];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int n = Serial.available();
  if (n > 0) {
    incomingByte = Serial.readBytes(buf, n);
    sprintf(outBuf, "I received %d bytes: %s", n, buf);
    Serial.println(outBuf);
  }
  delay(1000);
}
