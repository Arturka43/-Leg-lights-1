#include <FastLED.h>
#define NUM_LEDS 40 //Количество светодиодов
#define DATA_PIN 2

CRGB leds[NUM_LEDS];
int FastLED_fade_counter = 255;
int FastLED_fade_counterR = 100;
int FastLED_fade_counterB = 64;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  pinMode(2, OUTPUT); //выход на светодиодную ленту
  pinMode(4, INPUT); //левая зад
  pinMode(6, INPUT); //правая зад
  pinMode(8, INPUT); //правая перед
  pinMode(10, INPUT); //левая перед
  pinMode(12, INPUT); // + от габаритов
  
  digitalWrite(2, 0);
}

void  Scene_01W_fade_up () {
  for ( int i = 0; i < NUM_LEDS / 4; i++ ) {
    leds[i] = CHSV (0, 0, 255); // Зажигаем белым цветом нужную сторону
    leds[i].maximizeBrightness(FastLED_fade_counter);  // 'FastLED_fade_counter' How high we want to fade up to 255 = maximum.}
    FastLED_fade_counter ++ ;   // Increment
  }
}

void  Scene_01R_fade_up () {
  for ( int i = 0; i < NUM_LEDS / 4; i++ ) {
    leds[i] = CHSV(0,255,100); // включаем красную подсветку (можно изменить на любой цвет здесь)
    leds[i].maximizeBrightness(FastLED_fade_counterR);  // 'FastLED_fade_counter' How high we want to fade up to 255 = maximum.}
    FastLED_fade_counterR ++ ;   // Increment
    delay(20);
  }
}

void  Scene_01B_fade_down () {
  for ( int i = 0; i < NUM_LEDS / 4; i++ ) {
    leds[i] = CHSV (0, 0, 0); // Здесь можем указать любой цвет - выключаем подсветку
    leds[i].fadeToBlackBy(FastLED_fade_counterB);

    FastLED_fade_counterB ++ ;
  }
}

void loop() {
  boolean button5 = digitalRead(12); // + от габаритов
  boolean button6 = !digitalRead(10); //левая перед
  boolean button7 = !digitalRead(8); //правая перед
  boolean button8 = !digitalRead(6); //правая зад
  boolean button9 = !digitalRead(4); //левая зад

  if (button6 == 1) // если есть условная "1" при открытии двери - зажигаем водительскую сторону белым цветом
    Scene_01W_fade_up();
  FastLED.show();

  if (button5 == 1 & button6 == 0) //  проверяем 1 на габаритах, если есть, то зажигаем красным при закрытой двери
    Scene_01R_fade_up ();
  FastLED.show();

  if (button5 == 0 & button6 == 0)
    Scene_01B_fade_down ();
  FastLED.show();

  if (button7 == 1) // если есть условная "1" при открытии двери - зажигаем правая перед. белым цветом
    Scene_01W_fade_up();
  FastLED.show();

  if (button5 == 1 & button7 == 0) //  проверяем 1 на габаритах, если есть, то зажигаем красным при закрытой двери
    Scene_01R_fade_up ();
  FastLED.show();

  if (button5 == 0 & button7 == 0)
    Scene_01B_fade_down ();
  FastLED.show();

if (button8 == 1) // если есть условная "1" при открытии двери - зажигаем правая зад. белым цветом
    Scene_01W_fade_up();
  FastLED.show();

  if (button5 == 1 & button8 == 0) //  проверяем 1 на габаритах, если есть, то зажигаем красным при закрытой двери
    Scene_01R_fade_up ();
  FastLED.show();

  if (button5 == 0 & button8 == 0)
    Scene_01B_fade_down ();
  FastLED.show();  

if (button9 == 1) // если есть условная "1" при открытии двери - зажигаем левая зад. белым цветом
    Scene_01W_fade_up();
  FastLED.show();

  if (button5 == 1 & button9 == 0) //  проверяем 1 на габаритах, если есть, то зажигаем красным при закрытой двери
    Scene_01R_fade_up ();
  FastLED.show();

  if (button5 == 0 & button9 == 0)
    Scene_01B_fade_down ();
  FastLED.show();  
}
