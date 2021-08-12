/*
  Active_Buzzer

  modified 2021/7/1
  by http://www.freenove.com
*/

int buzzerPin = 7;    // the number of the buzzer pin

void setup() {
  pinMode(buzzerPin, OUTPUT); // Set Buzzer pin into output mode
}

void loop() {
    digitalWrite(buzzerPin, LOW);     // Turn off Buzzer
	delay(500);
    digitalWrite(buzzerPin, HIGH);    // Turn on Buzzer
	delay(500);
}
