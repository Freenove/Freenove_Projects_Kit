/*
  LED_Matrix

  modified 2021/7/1
  by http://www.freenove.com
*/

int latchPin = 12;          // Pin connected to ST_CP of 74HC595（Pin12）
int clockPin = 13;          // Pin connected to SH_CP of 74HC595（Pin11）
int dataPin = 11;           // Pin connected to DS of 74HC595（Pin14）

// Define the pattern data for a smiling face
const int smilingFace[] = {
  0x1C, 0x22, 0x51, 0x45, 0x45, 0x51, 0x22, 0x1C
};

// Define the data of numbers and letters, and save them in flash area
const int data[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // " "
  0x00, 0x00, 0x21, 0x7F, 0x01, 0x00, 0x00, 0x00, // "1"
  0x00, 0x00, 0x23, 0x45, 0x49, 0x31, 0x00, 0x00, // "2"
  0x00, 0x00, 0x22, 0x49, 0x49, 0x36, 0x00, 0x00, // "3"
  0x00, 0x00, 0x0E, 0x32, 0x7F, 0x02, 0x00, 0x00, // "4"
  0x00, 0x00, 0x79, 0x49, 0x49, 0x46, 0x00, 0x00, // "5"
  0x00, 0x00, 0x3E, 0x49, 0x49, 0x26, 0x00, 0x00, // "6"
  0x00, 0x00, 0x60, 0x47, 0x48, 0x70, 0x00, 0x00, // "7"
  0x00, 0x00, 0x36, 0x49, 0x49, 0x36, 0x00, 0x00, // "8"
  0x00, 0x00, 0x32, 0x49, 0x49, 0x3E, 0x00, 0x00, // "9"
  0x00, 0x00, 0x3E, 0x41, 0x41, 0x3E, 0x00, 0x00, // "0"
  0x00, 0x00, 0x3F, 0x44, 0x44, 0x3F, 0x00, 0x00, // "A"
  0x00, 0x00, 0x7F, 0x49, 0x49, 0x36, 0x00, 0x00, // "B"
  0x00, 0x00, 0x3E, 0x41, 0x41, 0x22, 0x00, 0x00, // "C"
  0x00, 0x00, 0x7F, 0x41, 0x41, 0x3E, 0x00, 0x00, // "D"
  0x00, 0x00, 0x7F, 0x49, 0x49, 0x41, 0x00, 0x00, // "E"
  0x00, 0x00, 0x7F, 0x48, 0x48, 0x40, 0x00, 0x00  // "F"
};

void setup() {
  // set pins to output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  // Define a one-byte variable (8 bits) which is used to represent the selected state of 8 column.
  int cols;
  // Display the static smiling pattern
  for (int j = 0; j < 500; j++ ) {  // repeat 500 times
    cols = 0x01; // Assign 0x01(binary 00000001) to the variable, which represents the first column is selected.
    for (int i = 0; i < 8; i++) {   // display 8 column data by scaning
      matrix(smilingFace[i],cols);
      delay(1);                     // display them for a period of time
      cols <<= 1;                   // shift"cols" 1 bit left to select the next column
    }
  }
  // Display the dynamic patterns of numbers and letters
  for (int i = 0; i < 128; i++) { // "space，0-9，A-F"16 letters ,each letter hold 8 columns, total 136 columns. Firstly, display space ,then we need shift 128 times（136-8）
    for (int k = 0; k < 10; k++) {      // repeat image of each frame 10 times.
      cols = 0x01;      // Assign binary 00000001. Means the first column is selected.
      for (int j = i; j < 8 + i; j++) { // display image of each frame
        matrix(pgm_read_word_near(data + j),cols);
        delay(1);                       // display them for a period of time
        cols <<= 1;                 // shift"cols" 1 bit left to select the next column
      }
    }
  }
}

void matrix(byte row_value,byte col_value) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, row_value);
  shiftOut(dataPin, clockPin, MSBFIRST, ~col_value);
  digitalWrite(latchPin, HIGH);
}
