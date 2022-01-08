String inputString = "";
bool stringComplete = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Digital Caculator");
}

void loop() {
  // put your main code here, to run repeatedly:
  int len, n, a, b, ans;
  int ch;
  int sw = 0;

  if (stringComplete) {
    len = inputString.length();
    a = b = sw = 0;
    for (n = 0; n < len; n++) {
      ch = inputString.charAt(n);
      if (ch == '+') {
        sw = 1;
      }
      else if (ch >= '0' && ch <= '9') {
        if (sw == 0)
          a = a * 10 + ch - '0';
        else
          b = b * 10 + ch - '0';
      }
      else if (ch == '=') {
        ans = a + b;
      }
    }
    inputString = String(a) + '+' + String(b) + '=' + String(ans);
    Serial.println(inputString);

    inputString = "";
    sw = 0;
    stringComplete = false;
  }
}

void seralEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
