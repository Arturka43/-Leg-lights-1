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
  boolean button5 = digitalRead(4); // + from dimensions
  boolean button6 = !digitalRead(6); //left in front
  boolean button7 = !digitalRead(7); //right in front
  boolean button8 = !digitalRead(12); //right in rear
  boolean button9 = !digitalRead(9); //left in rear

  if (button6 == 1) // if there is a conditional "1" when opening the door - light the driver's side in white
    Scene_01W_fade_up();
  FastLED.show();

  if (button5 == 1 & button6 == 0) // check 1 on the dimensions, if there is, then light it up in red with the door closed
    Scene_01R_fade_up ();
  FastLED.show();

  if (button5 == 0 & button6 == 0) // turn off
    Scene_01B_fade_down ();
  FastLED.show();
}
