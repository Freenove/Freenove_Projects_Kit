/*
  Joystick

  modified 2021/7/1
  by http://www.freenove.com
*/

int xVal, yVal, zVal;       // define 3 variables to store the values of 3 direction

void setup() {
  pinMode(A3, INPUT);       // initialize the port to input
  Serial.begin(9600);       // initialize the serial port with baud rate 9600
}

void loop() {
  // read analog value in XY axis
  xVal = analogRead(A1);
  yVal = analogRead(A2);
  // read digital value of switch in Z axis
  zVal = digitalRead(A3);
  //print the data read above
  Serial.print("X : ");
  Serial.print(xVal);
  Serial.print("   \t Y : ");
  Serial.print(yVal);
  Serial.print("   \t Z : ");
  Serial.println(zVal);
  delay(200);
}
