/*
  Control_Servo_by_Potentiometer

  modified 2021/7/1
  by http://www.freenove.com
*/

#include <Servo.h>

Servo myservo;              // create servo object to control a servo

int servoPin = 3;           // define the pin of servo signal line
int potVal;                 // variable to read the potValue from the analog pin

void setup() {
  myservo.attach(servoPin); // attaches the servo on servoPin to the servo object
  Serial.begin(115200);
}

void loop() {
  potVal = analogRead(A1);              // reads the potValue of the potentiometer
  Serial.println(potVal);
  potVal = map(potVal, 0, 1023, 0, 180);// scale it to use it with the servo
  myservo.write(potVal);                // sets the servo position
  delay(15);                            // waits for the servo to get there
}
