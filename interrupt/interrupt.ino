#define LED 11
#define TOUCH 3

uint8_t ledValue;

void setup() {
  // put your setup code here, to run once:
pinMode(TOUCH, INPUT);
  pinMode(LED, OUTPUT);
digitalWrite(LED, ledValue);
  attachInterrupt(digitalPinToInterrupt(TOUCH), ISR_INT1, RISING);
ledValue = 0;
}

void ISR_INT1()
{
  ledValue ^= 1;
  digitalWrite(LED, ledValue);
}

void loop() {
  // put your main code here, to run repeatedly:
}
