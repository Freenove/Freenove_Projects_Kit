/*
  Rainbow

  modified 2021/7/2
  by http://www.freenove.com
*/

#include <Adafruit_NeoPixel.h>

#define PIN 5
#define NUMBER 8
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMBER, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(50);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  int analogValue = analogRead(A1);
  int colorPos = map(analogValue, 0, 1023, 0, 255);
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i,Wheel(colorPos + i * 255 / 8));
  }
  strip.show();
  delay(10);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
