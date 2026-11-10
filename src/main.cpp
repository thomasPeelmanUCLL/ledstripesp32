#include <Arduino.h>
#include <FastLED.h>

#define LED_PIN 16
#define NUM_LEDS 250
#define BRIGHTNESS 60

CRGB leds[NUM_LEDS];

void setup() {
    Serial.begin(115200);
    delay(1000);

    FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
    FastLED.clear(true);
}

void loop() {
    // Smooth breathing: 8 breaths per minute
    uint8_t brightness = beatsin8(8, 40, 255);

    // One consistent color across the whole strip
    CRGB color = CRGB(0, 80, 255); // calm blue

    fill_solid(leds, NUM_LEDS, color);
    FastLED.setBrightness(brightness);
    FastLED.show();

    delay(20);
}