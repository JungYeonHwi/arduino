#include "IRSendRev.h"
#define IR_OUT_PIN 5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  IR.Init(IR_OUT_PIN);
  Serial.print("init over");
}

unsigned char dta[20];

void loop() {
  // put your main code here, to run repeatedly:

  if(IR.IsDta()) {
    IR.Recv(dta);
    Serial.print("len = ");Serial.print(dta[D_LEN]); // 전체 길이 (dta[0] 제외) Serial.print(" SH = ");Serial.print(dta[D_STARTH]); // Start H
    Serial.print(" SL = ");Serial.print(dta[D_STARTL]); // Start L
    Serial.print(" short = ");Serial.print(dta[D_SHORT]); // Mark(0), Low 길이
    Serial.print(" long = ");Serial.print(dta[D_LONG]); // Space(1), Low 길이
    Serial.print(" DLen = ");Serial.print(dta[D_DATALEN]); // payload 길이
    for(int i = 0; i<dta[D_DATALEN]; i++) {
       Serial.print(" ");
       Serial.print(dta[D_DATA+i], HEX);
       }
     Serial.print("\n");
  }
}
