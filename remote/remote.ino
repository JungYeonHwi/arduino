#include "IRSendRev.h"
#include <TM1637Display.h>

#define DIO 11
#define CLK 10
#define IR_OUT_PIN 5

TM1637Display FND(CLK, DIO);

int num = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  IR.Init(IR_OUT_PIN);
  FND.setBrightness(0x04);
  FND.showNumberDecEx(num);
}

unsigned char dta[20];
String data = "";
String str ="";
int data_num = 0;
int temp = 0;

void loop() {
  // put your main code here, to run repeatedly:

  if(IR.IsDta()) {
    IR.Recv(dta);
    
    for(int i = 2; i<dta[D_DATALEN]; i++) {
       data += dta[D_DATA+i];
    }
    
    if (data.equals("104151")) { // 0을 누른 경우
      str += "0";
    }
    if (data.equals("48207")) { // 1을 누른 경우
      str += "1";
    }
    if (data.equals("24231")) { // 2을 누른 경우
      str += "2";
    }
    if (data.equals("122133")) { // 3을 누른 경우
      str += "3";
    }
    if (data.equals("16239")) { // 4을 누른 경우
      str += "4";
    }
    if (data.equals("56199")) { // 5을 누른 경우
      str += "5";
    }
    if (data.equals("90165")) { // 6을 누른 경우
      str += "6";
    }
    if (data.equals("66189")) { // 7을 누른 경우
      str += "7";
    }
    if (data.equals("74181")) { // 8을 누른 경우
      str += "8";
    }
    if (data.equals("82173")) { // 9을 누른 경우
      str += "9";
    }
    if (data.equals("2253")) { // +을 누른 경우
      data_num = data_num + 1;
      str = (String)data_num;     
    }
    if (data.equals("152103")) { // -을 누른 경우
      data_num = data_num - 1; 
      str = (String)data_num;   
    }
    if (data.equals("17679")) { // c을 누른 경우
      data_num = 0; // 0으로 초기화
      str = (String)data_num;
    }

    data_num = str.toInt(); // string인 str을 data_num에 int화 시키기
    
    temp = data_num; // 숫자가 4자리가 넘은 경우에 이상한 값이 들어오므로 예외 처리하기 위해 이전 값 대입
    if (data_num > 9999) { 
      str = str.substring(0,4); // 앞의 4자리만 넣어주기
      data_num = str.toInt();
    }
    FND.showNumberDecEx(data_num); 
    data = "";
  }
}
