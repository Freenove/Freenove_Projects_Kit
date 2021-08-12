/*
  Passive_Buzzer

  modified 2021/7/1
  by http://www.freenove.com
*/

int buzzerPin = 6;    // the number of the buzzer pin
int keyPin = 2;       // the number of the key1 pin
float sinVal;         // Define a variable to save sine value
int toneVal;          // Define a variable to save sound frequency

void setup() {
  pinMode(buzzerPin, OUTPUT); // Set Buzzer pin to output mode
  pinMode(keyPin, INPUT);     // Set Key1 pin to input mode
}

void loop() {
  if (digitalRead(keyPin) == LOW) {
    for (int x = 0; x < 360; x++) {       // X from 0 degree->360 degree
      sinVal = sin(x * (PI / 180));       // Calculate the sine of x
      toneVal = 2000 + sinVal * 500;      // Calculate sound frequency according to the sine of x
      tone(buzzerPin, toneVal);           // Output sound frequency to buzzerPin
      delay(1);
    }
  }
  else
    noTone(buzzerPin);
}
