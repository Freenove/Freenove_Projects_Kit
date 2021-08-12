/*
  Digital_Tube

  modified 2021/7/1
  by http://www.freenove.com
*/

int latchPin = 12;          // Pin connected to ST_CP of 74HC595（Pin12）
int clockPin = 13;          // Pin connected to SH_CP of 74HC595（Pin11）
int dataPin = 11;           // Pin connected to DS of 74HC595（Pin14）

byte num[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8,//0-7
              0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e};//8-F

void setup() {
  // set pins to output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  for(int j=0;j<100;j++){
    for (int i = 0; i < 4; i++){
      DigitalTube_MSBFIRST(i, num[i]);
      delay(5);
    }
  }
}

void DigitalTube_MSBFIRST(int number, byte value){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0x01 << number);
  shiftOut(dataPin, clockPin, MSBFIRST, value);
  digitalWrite(latchPin, HIGH);
}
