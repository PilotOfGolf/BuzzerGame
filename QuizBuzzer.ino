// Pins for buttons
const unsigned char switches[4] = {A0, A1, A2, A3};

// Pins for LEDs
const unsigned char leds[4] = {9, 10, 11, 12};

// Reset button
const unsigned char switch_reset = 6;

void setup() {
  // Prepare the pins
  pinMode(switch_reset, INPUT_PULLUP);  
  for (unsigned char sw=0; sw<4; sw++) {
    pinMode(switches[sw], INPUT_PULLUP);
    pinMode(leds[sw], OUTPUT);
    digitalWrite(leds[sw], LOW);
  }
}

void neoRed() {

}

void neoGreen() {

}

void neoWhite() {

}

void neoBlue() {

}

// Main loop
void loop() {
  // Check all 4 switches
  for (unsigned char sw=0; sw<4; sw++) {
    
    // Is it pressed?
    if (digitalRead(switches[sw]) == LOW) {
      
      // Turn on its LED
      digitalWrite(leds[sw], HIGH);

      // Set the NeoPixel To the right color
      

      // Wait for the reset button
      while (digitalRead(switch_reset) == HIGH) {};
      
      // Turn off the LED
      digitalWrite(leds[sw], LOW);
      
      // Stop!
      break;
    }
  }
}
