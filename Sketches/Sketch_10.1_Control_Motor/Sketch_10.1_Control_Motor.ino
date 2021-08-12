/*
  Control_Motor

  modified 2021/7/1
  by http://www.freenove.com
*/

int IN1Pin = 9;       // Define Motor pin1
int IN2Pin = 10;      // Define Motor pin2

boolean rotationDir;  // Define a variable to save the motor's rotation direction, true and false are represented by positive rotation and reverse rotation.
int rotationSpeed;    // Define a variable to save the motor rotation speed

void setup() {
  // Initialize the pin into an output mode:
  pinMode(IN1Pin, OUTPUT);
  pinMode(IN2Pin, OUTPUT);
}

void loop() {
  int potenVal = analogRead(A1);  // Convert the voltage of rotary potentiometer into digital
  
  // Compare the number with value 512, if more than 512, clockwise rotates, otherwise, counter clockwise rotates
  rotationSpeed = potenVal - 512;
  if (potenVal > 512)
    rotationDir = true;
  else
    rotationDir = false;
  // Calculate the motor speed, the far number of deviation from the middle value 512, the faster the control speed will be
  rotationSpeed = abs(potenVal - 512);
  // Control the steering and speed of the motor
  driveMotor(rotationDir, map(rotationSpeed, 0, 512, 0, 255));
  delay(10);
}

void driveMotor(boolean dir, int spd) {
  // Control motor rotation direction
  if (dir){
    analogWrite(IN1Pin,spd);
    analogWrite(IN2Pin,0);
  }
  else{
    analogWrite(IN1Pin,0);
    analogWrite(IN2Pin,spd);
  }
}
