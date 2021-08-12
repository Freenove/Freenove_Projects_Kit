/*
  Receive_Data_through_Serial_Port

  modified 2021/6/30
  by http://www.freenove.com
*/

String str;      // define a variable to store strings received from serial port

void setup() {
  Serial.begin(9600);                 // initialize serial port, set baud rate to 9600
}

void loop() {
  if (Serial.available()) {         // judge whether data has been received
    str = Serial.readString();      // read one character
    Serial.print("Control Board received:");  // print the string "Control Board received:"
    Serial.println(str);            // print the received character
  }
}
