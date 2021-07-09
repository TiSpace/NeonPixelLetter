/*

*/

#define PIN_WS2812B     4
#define PIN_TASTE       2
#define LED_COUNT       27 // number of connected WS2812B mmmmmmmmmmmm


int TasterCount = 1;
int Taste;
int TasteVorher = 1;

#include <FastLED.h>

//#define NUM_LEDS (20)


CRGBArray<LED_COUNT> leds;

uint8_t delayValue = 20; // delay
uint8_t stepValue = 10; // pixel pitch
uint8_t hueValue = 0; // color tone
uint8_t bright = 25; // Brightness (0 - 255) -> bright=0 leads to sstrange LED Effects

void setup() {
  pinMode(PIN_TASTE, INPUT_PULLUP);
  Serial.begin(38400);
  LEDS.setBrightness(bright);
  LEDS.addLeds<WS2812B, PIN_WS2812B, GRB>(leds, LED_COUNT);  // settings for your tape (tapes on WS2811, WS2812, WS2812B)
  updateColor(0, 0, 0);
  LEDS.show();

}

void loop() {
  Taste = digitalRead(PIN_TASTE);
  if (Taste != TasteVorher)
  {
    if (TasteVorher == 0)
    {
      TasterCount++;
      Serial.println("Taste");
    }
  }
  TasteVorher = Taste;

  if (TasterCount >= 29)//mmmmmmmmmmmmmmm
  {
    TasterCount = 1;
  }
  Serial.println(TasterCount);
  ledEffect(TasterCount);
}
