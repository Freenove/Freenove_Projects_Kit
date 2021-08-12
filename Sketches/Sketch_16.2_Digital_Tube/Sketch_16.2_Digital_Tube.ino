/*
  Digital_Tube

  modified 2021/7/1
  by http://www.freenove.com
*/

int latchPin = 12;          // Pin connected to ST_CP of 74HC595（Pin12）
int clockPin = 13;          // Pin connected to SH_CP of 74HC595（Pin11）
int dataPin = 11;           // Pin connected to DS of 74HC595（Pin14）
int countValue = 0;        // Digital tube display value

byte num[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8,//0-7
              0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e
             };//8-F

void setup() {
  // set pins to output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  for (int j = 0; j < 250; j++) {
    ShowCount(countValue);
  }
  countValue++;
}

void ShowCount(int value) {
  DigitalTube_MSBFIRST(0, num[value % 10000 / 1000]); delay(1);
  DigitalTube_MSBFIRST(1, num[value % 1000 / 100]);   delay(1);
  DigitalTube_MSBFIRST(2, num[value % 100 / 10]);     delay(1);
  DigitalTube_MSBFIRST(3, num[value % 10]);           delay(1);
}

void DigitalTube_MSBFIRST(int number, byte value) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0x01 << number);
  shiftOut(dataPin, clockPin, MSBFIRST, value);
  digitalWrite(latchPin, HIGH);
}
