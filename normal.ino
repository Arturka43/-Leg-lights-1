#include <FastLED.h>

#define NUM_LEDS 40 //Количество светодиодов
#define DATA_PIN 10

CRGB leds[NUM_LEDS];

int FastLED_fade_counter = 255;
int FastLED_fade_counterR = 100;
int FastLED_fade_counterB = 64;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  pinMode(10, OUTPUT);
  pinMode(4, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(12, INPUT);
  pinMode(9, INPUT);

  digitalWrite(10, 0);
}

void loop() {
  boolean button5 = digitalRead(4); // + from dimensions
  boolean button6 = !digitalRead(6); //left in front
  boolean button7 = !digitalRead(7); //right in front
  boolean button8 = !digitalRead(12); //right in rear
  boolean button9 = !digitalRead(9); //left in rear

  if (button6 == 1) // if there is a conditional "1" when opening the door - light the driver's side in white
    for (int i = 0; i < NUM_LEDS / 4; i++) {
      leds[i] = CHSV (0,0,255);
      FastLED.show();
    }
  else if (button5 == 1) // otherwise we check 1 on the dimensions, if there is, then light it up in red
    for (int i = 0; i < NUM_LEDS / 4; i++) {
      leds[i] = CHSV( 0, 100, 100);
      FastLED.show();
      delay(50);
    }
  else
    for (int i = 0; i < NUM_LEDS / 4; i++) { //if 0 is everywhere, fill it with black.
      leds[i] = CHSV( 0, 0, 0);
      FastLED.show();
      delay(50);
    }

  if (button7 == 1) // если есть условная "1" при открытии двери - зажигаем пассажирскую сторону белым цветом
    for (int i = NUM_LEDS / 4; i < NUM_LEDS * 2 / 4; i++) {
      leds[i] = CHSV( 0, 0, 100);
      FastLED.show();
      delay(50);
    }
  else if (button5 == 1) // иначе  проверяем 1 на габаритах, если есть, то зажигаем красным
    for (int i = NUM_LEDS / 4; i < NUM_LEDS * 2 / 4; i++) {
      leds[i] = CHSV( 0, 100, 100);
      FastLED.show();
      delay(50);
    }
  else
    for (int i = NUM_LEDS / 4; i < NUM_LEDS * 2 / 4; i++) { //если везде по 0 - заливаем чёрным.
      leds[i] = CHSV( 0, 0, 0);
      FastLED.show();
      delay(50);
    }

  if (button8 == 1) // если есть условная "1" при открытии двери - зажигаем заднюю правую сторону белым цветом
    for (int i = NUM_LEDS * 2 / 4; i < NUM_LEDS * 3 / 4; i++) {
      leds[i] = CHSV( 0, 0, 100);
      FastLED.show();
      delay(50);
    }
  else if (button5 == 1) // иначе  проверяем 1 на габаритах, если есть, то зажигаем красным
    for (int i = NUM_LEDS * 2 / 4; i < NUM_LEDS * 3 / 4; i++) {
      leds[i] = CHSV( 0, 100, 100);
      FastLED.show();
      delay(50);
    }
  else
    for (int i = NUM_LEDS * 2 / 4; i < NUM_LEDS * 3 / 4; i++) { //если везде по 0 - заливаем чёрным.
      leds[i] = CHSV( 0, 0, 0);
      FastLED.show();
      delay(50);
    }

  if (button9 == 1) // если есть условная "1" при открытии двери - зажигаем заднюю левую сторону белым цветом
    for (int i = NUM_LEDS * 3 / 4; i < NUM_LEDS; i++) {
      leds[i] = CHSV( 0, 0, 100);
      FastLED.show();
      delay(50);
    }
  else if (button5 == 1) // иначе  проверяем 1 на габаритах, если есть, то зажигаем красным
    for (int i = NUM_LEDS * 3 / 4; i < NUM_LEDS; i++) {
      leds[i] = CHSV( 0, 100, 100);
      FastLED.show();
      delay(50);
    }
  else
    for (int i = NUM_LEDS * 3 / 4; i < NUM_LEDS; i++) { //если везде по 0 - заливаем чёрным.
      leds[i] = CHSV( 0, 0, 0);
      FastLED.show();
      delay(50);
    }
}
