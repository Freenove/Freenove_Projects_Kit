/*
  LEDPixel

  modified 2021/7/2
  by http://www.freenove.com
*/

#include <Adafruit_NeoPixel.h>

#define PIN        5 // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS  8 // Popular NeoPixel ring size
#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
u8 m_color[5][3] = { {20, 0, 0}, {0, 20, 0}, {0, 0, 20}, {20, 20, 20}, {0, 0, 0} };

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  for(int j=0;j<5;j++){
    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
      pixels.setPixelColor(i, pixels.Color(m_color[j][0], m_color[j][1], m_color[j][2]));
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
}
