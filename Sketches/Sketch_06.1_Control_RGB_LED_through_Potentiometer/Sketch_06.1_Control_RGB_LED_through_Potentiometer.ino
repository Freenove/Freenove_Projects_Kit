/*
  Control_RGB_LED_through_Potentiometer

  modified 2021/6/30
  by http://www.freenove.com
*/

// set pin numbers:
int ledPinR = 11;   // the number of the LED R pin
int ledPinG = 10;   // the number of the LED G pin
int ledPinB = 9;    // the number of the LED B pin

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinB, OUTPUT);
}

void loop() {
  int adcValue;     // Define a variable to save the ADC value
  // Convert analog of A1 port into digital, and work as PWM duty cycle of ledPinR port
  adcValue = analogRead(A1);
  analogWrite(ledPinR, map(adcValue, 0, 1023, 0, 255));
  // Convert analog of A2 port into digital, and work as PWM duty cycle of ledPinG port
  adcValue = analogRead(A2);
  analogWrite(ledPinG, map(adcValue, 0, 1023, 0, 255));
  // Convert analog of A3 port into digital, and work as PWM duty cycle of ledPinB port
  adcValue = analogRead(A3);
  analogWrite(ledPinB, map(adcValue, 0, 1023, 0, 255));
}
