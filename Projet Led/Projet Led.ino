#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    12

CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
}

void loop() {
  for (int i = 0; i <= 11; i++) {
    leds[i] = CRGB ( 10, 10, 10);
    FastLED.show();
    delay(100);
  }
  for (int i = 11; i >= 0; i--) {
    leds[i] = CRGB ( random(10), random(10), random(10));
    FastLED.show();
    delay(100);
    }
  for (int i = 0; i <= 11; i++) {
    leds[i] = CRGB ( random(10), random(10), random(10));
    FastLED.show();
    delay(100);
  }
  for (int i = 11; i >= 0; i--) {
    leds[i] = CRGB ( random(10), random(10), random(10));
    FastLED.show();
    delay(100);
    }
  for (int i = 11; i >= 0; i--) {
    leds[i] = CRGB ( 10, 10, 10);
    FastLED.show();
    delay(100);
    }
}
