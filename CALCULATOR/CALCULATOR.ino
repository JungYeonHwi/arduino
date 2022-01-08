int A, B;
char OP;
bool calcFlag = false;
String outString;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("=== DIGITAL CALCULATOR ===");
  calState = 0;
  A = B = 0;
  calcFlag = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  int ans;
  if (calcFlag == true) {
    ans = 0;
    switch(OP) {
      case 0 : break;
      case '+' : ans = A + B; break;
      case '-' : ans = A - B; break;
      case '*' : ans = A * B; break;
      case '/' : if (B != 0) ans = A / B; break;
    }
    outString = String(A) + Op + String(B) + '=' + String(ans);
    Serial.println(outString);
    calcFlag = false;
    A = B = 0;
  }
}
