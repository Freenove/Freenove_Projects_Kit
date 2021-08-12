/*
  Control_LED_by_Potentiometer
  
  modified 2021/6/30
  by http://www.freenove.com
*/

int adcValue;     // Define a variable to save the ADC value
int ledPin = 6;   // Use D9 on Freenove UNO to control the LED

void setup() {
  pinMode(ledPin, OUTPUT);             // Initialize the LED pin as an output
}

void loop() {
  adcValue = analogRead(A1);          // Convert the analog of A0 port to digital
  // Map analog to the 0-255 range, and works as PWM duty cycle of ledPin port
  analogWrite(ledPin, map(adcValue, 0, 1023, 0, 255));
}
