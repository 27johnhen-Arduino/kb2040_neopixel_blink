#include "kb2040pins.h"
#include "Adafruit_NeoPixel.h"
#define NUMPIXELS 1
Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL, NEO_GRB + NEO_KHZ800);

float brightness = 1;
float factor = 1.5;
bool reciprocal = false;
int delaytime = 10;

void setup() {
  Serial.begin(9600);

  pixels.begin();
  pixels.fill(0x00FFFF);
}

void loop() {
  Serial.println(brightness);
  pixels.setBrightness(brightness);
  pixels.show();
  delay(delaytime);
  if (reciprocal == false) {
    brightness *= factor;
  }
  if (reciprocal == true) {
    brightness /= factor;
  }
  if (brightness <= 1) {
    reciprocal = false;
  }
  if (brightness > 100) {
    reciprocal = true;
  }
}
