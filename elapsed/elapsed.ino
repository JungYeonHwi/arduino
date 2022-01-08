char buf(80);

void setup() {
   Serial.begin(115200);
}

void loop() {
  unsigned long elapsed;

  elapsed = micros();
  
  Serial.println("0123456789"); // 10 + 0x0d + 0x0a - 12byte
  Serial.flush();
  
  elapsed = micros() - elapsed;

  sprintf(buf, "elpased time %d", elapsed);
  Serial.println(buf);
  delay(1000);
}
