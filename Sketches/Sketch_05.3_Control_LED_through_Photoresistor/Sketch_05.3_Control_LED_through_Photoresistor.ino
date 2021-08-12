/*
  Control_LED_through_Photoresistor

  modified 2021/6/30
  by http://www.freenove.com
*/

int convertValue; // Define a variable to save the ADC value
int ledPin = 6;   // The number of the LED pin

void setup() {
  pinMode(ledPin, OUTPUT);  // Set ledPin into output mode
}

void loop() {
  convertValue = analogRead(A0);  // Read analog voltage value of A0 port, and save
  // Map analog to the 0-255 range, and works as ledPin duty cycle setting
  analogWrite(ledPin, map(convertValue, 0, 1023, 0, 255));
}
