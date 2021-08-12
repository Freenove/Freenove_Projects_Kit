/*
  Application_of_Serial

  modified 2021/6/30
  by http://www.freenove.com
*/

int inInt;        // define a variable to store the data received from serial
int counter = 0;  // define a variable as the data sending to serial
int ledPin = 6;   // the number of the LED pin

void setup() {
  pinMode(ledPin, OUTPUT);              // initialize the LED pin as an output
  Serial.begin(9600);                   // initialize serial port, set baud rate to 9600
  Serial.println("Control Board is ready!");     // print the string "Control Board is ready!"
}

void loop() {
  if (Serial.available()) {         // judge whether the data has been received
    inInt = Serial.parseInt();      // read an integer
    Serial.print("Control Board received:");  // print the string "Control Board received:"
    Serial.println(inInt);          // print the received character
    counter = constrain(inInt,0,255);
    analogWrite(ledPin,counter);
  }
}
