/*
  Send_data_through_Serial

  modified 2021/6/30
  by http://www.freenove.com
*/

int counter = 0;  // define a variable as a data sending to serial port

void setup() {
  Serial.begin(9600);                 // initialize the serial port, set the baud rate to 9600
}

void loop() {
  // print variable counter value to serial
  Serial.print("counter:");   // print the string "counter:"
  Serial.println(counter);    // print the variable counter value
  delay(500);                 // wait 500ms to avoid cycling too fast
  counter++;                  // variable counter increases 1
}
