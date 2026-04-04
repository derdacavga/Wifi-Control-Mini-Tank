#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 2
#define DATA_PIN D5

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {

  leds[0] = CRGB::Red;
  leds[1] = CRGB::Red;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  FastLED.show();

  leds[0] = CRGB::Green;
  leds[1] = CRGB::Green;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  FastLED.show();

  leds[0] = CRGB::Blue;
  leds[1] = CRGB::Blue;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  FastLED.show();
}
