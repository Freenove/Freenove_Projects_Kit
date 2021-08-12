/*
  74HC595_LEDBAR

  modified 2021/7/1
  by http://www.freenove.com
*/

int latchPin = 12;          // Pin connected to ST_CP of 74HC595（Pin12）
int clockPin = 13;          // Pin connected to SH_CP of 74HC595（Pin11）
int dataPin = 11;           // Pin connected to DS of 74HC595（Pin14）

void setup() {
  // set pins to output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

}

void loop() {
  int val=0x01;
  for(int i=0;i<10;i++)
  {
    LedBar_MSBFIRST(val);
    delay(100);
    val<<=1;
  }
  val=0x200;
  for(int i=0;i<10;i++)
  {
    LedBar_MSBFIRST(val);
    delay(100);
    val>>=1;
  }
}

void LedBar_MSBFIRST(int value)
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, value>>8);//Send high 8 bits of data, high bits first
  shiftOut(dataPin, clockPin, MSBFIRST, value);//Send low 8 bits of data, high bits first
  digitalWrite(latchPin, HIGH);
}
