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

void  Scene_01W_fade_up () {
  for ( int i = 0; i < NUM_LEDS / 4; i++ ) {
    leds[i] = CHSV (0, 0, 255); // Can be any colour
    leds[i].maximizeBrightness(FastLED_fade_counter);  // 'FastLED_fade_counter' How high we want to fade up to 255 = maximum.}
    FastLED.show();
    FastLED_fade_counter ++ ;   // Increment
  }
}

void  Scene_01R_fade_up () {
  for ( int i = 0; i < NUM_LEDS / 4; i++ ) {
    leds[i] = CHSV(0,255,100); // Can be any colour
    leds[i].maximizeBrightness(FastLED_fade_counterR);  // 'FastLED_fade_counter' How high we want to fade up to 255 = maximum.}
    FastLED.show();
    FastLED_fade_counterR ++ ;   // Increment
    delay(20);
  }
}

void  Scene_01B_fade_down () {
  for ( int i = 0; i < NUM_LEDS / 4; i++ ) {
    leds[i] = CHSV (0, 0, 0); // Can be any colour
    leds[i].fadeToBlackBy(FastLED_fade_counterB);
    FastLED.show();
    FastLED_fade_counterB ++ ;
  }
}

void loop() {
  boolean button5 = digitalRead(4); // + от габаритов
  boolean button6 = !digitalRead(6); //левая перед
  boolean button7 = !digitalRead(7); //правая перед
  boolean button8 = !digitalRead(12); //правая зад
  boolean button9 = !digitalRead(9); //левая зад

  if (button6 == 1) // если есть условная "1" при открытии двери - зажигаем водительскую сторону белым цветом
    Scene_01W_fade_up();
  FastLED.show();

  if (button5 == 1 & button6 == 0) //  проверяем 1 на габаритах, если есть, то зажигаем красным при закрытой двери
    Scene_01R_fade_up ();
  FastLED.show();

  if (button5 == 0 & button6 == 0)
    Scene_01B_fade_down ();
  FastLED.show();
}
