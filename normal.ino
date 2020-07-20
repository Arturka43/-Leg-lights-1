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
  boolean button5 = digitalRead(4); // + от габаритов
  boolean button6 = !digitalRead(6); //левая перед
  boolean button7 = !digitalRead(7); //правая перед
  boolean button8 = !digitalRead(12); //правая зад
  boolean button9 = !digitalRead(9); //левая зад

  if (button6 == 1) // если есть условная "1" при открытии двери - зажигаем водительскую сторону белым цветом
    for (int i = 0; i < NUM_LEDS / 4; i++) {
      leds[i] = CRGB::White;
      leds[i].maximizeBrightness(FastLED_fade_counter);  // 'FastLED_fade_counter' How high we want to fade up to 255 = maximum.}
      FastLED_fade_counter ++ ;   // Increment
      FastLED.show();
    }
  else if (button5 == 1) // иначе  проверяем 1 на габаритах, если есть, то зажигаем красным
    for (int i = 0; i < NUM_LEDS / 4; i++) {
      leds[i] = CHSV( 0, 100, 100);
      FastLED.show();
      delay(50);
    }
  else
    for (int i = 0; i < NUM_LEDS / 4; i++) { //если везде по 0 - заливаем чёрным.
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
