#include <Adafruit_NeoPixel.h>

#define PIN        3
#define NUMPIXELS 8

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_RGBW + NEO_KHZ800);

// Pins for buttons
const unsigned char switches[4] = {A0, A1, A2, A3};

// Pins for LEDs
const unsigned char leds[4] = {9, 10, 11, 12};

// Reset button
const unsigned char switch_reset = A5;

void setup() {
  // Prepare the pins
  pinMode(switch_reset, INPUT_PULLUP);  
  for (unsigned char sw=0; sw<4; sw++) {
    pinMode(switches[sw], INPUT_PULLUP);
    pinMode(leds[sw], OUTPUT);
    digitalWrite(leds[sw], LOW);
  }
    pixels.begin();
    pixels.clear();
}


void neoRed() {
  pixels.fill(pixels.Color(0, 255, 0));
  pixels.show();

}

void neoGreen() {
  pixels.fill(pixels.Color(255, 0, 0));
  pixels.show();


}

void neoWhite() {
  pixels.fill(pixels.Color(255, 255, 255, 255));
  pixels.show();


}

void neoBlue() {
  pixels.fill(pixels.Color(0, 0, 255));
  pixels.show();


}

void lightNeo(int pin) {
  if (pin == 0) {
    neoGreen();
  }
  if (pin == 1) {
    neoBlue();
  }
  if (pin == 2) {
    neoWhite();
  }
  if (pin == 3) {
    neoRed();
  }
}

// Main loop
void loop() {
  pixels.setBrightness(155);
  // Check all 4 switches
  for (unsigned char sw=0; sw<4; sw++) {
    
    // Is it pressed?
    if (digitalRead(switches[sw]) == LOW) {   // low
      
      // Turn on its LED
      digitalWrite(leds[sw], HIGH);

      // Set the NeoPixel To the right color
      lightNeo(sw);

      // Wait for the reset button
      while (digitalRead(switch_reset) == HIGH) {};
      
      // Turn off the LED
      digitalWrite(leds[sw], LOW);
      pixels.fill(pixels.Color(0, 0, 0));
      // Stop!
      break;
    }
  }
}
