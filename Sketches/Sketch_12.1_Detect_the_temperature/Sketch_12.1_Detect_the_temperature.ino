/*
  Detect_the_temperature

  modified 2021/7/1
  by http://www.freenove.com
*/

void setup() {
  Serial.begin(9600);// Initialize the serial port, set the baud rate into 9600
}

void loop() {
  // Convert analog value of A0 port into digital value
  int adcVal = analogRead(A0);
  // Calculate voltage
  float v = adcVal * 5.0 / 1024;
  // Calculate resistance value of thermistor
  float Rt = 10 * v / (5 - v);
  // Calculate temperature (Kelvin)
  float tempK = 1 / (log(Rt / 10) / 3950 + 1 / (273.15 + 25));
  // Calculate temperature (Celsius)
  float tempC = tempK - 273.15;

  // Send the result to computer through serial port
  Serial.print(adcVal);
  Serial.print("\tCurrent temperature is: ");
  Serial.print(tempK);
  Serial.print(" K, ");
  Serial.print(tempC);
  Serial.println(" C");
  delay(500);
}
