/*
  Infrared_Motion_Sensor

  modified 2021/7/2
  by http://www.freenove.com
*/

int sensorPin = 2; // the number of the infrared motion sensor pin
int ledPin = 13;    // the number of the LED pin

void setup() {
  pinMode(sensorPin, INPUT);  // initialize the sensor pin as input
  pinMode(ledPin, OUTPUT);    // initialize the LED pin as output
}

void loop() {
  // Turn on or off LED according to Infrared Motion Sensor
  digitalWrite(ledPin,digitalRead(sensorPin));
  delay(100);              // wait for a second
}
