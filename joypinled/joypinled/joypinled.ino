#include <Adafruit_NeoPixel.h>
int DataIn = 12;
int i;
#define LED_PIN    6
#define LED_COUNT 12
#define NUM_JOY 2
#define MIN_VAL 0
#define MAX_VAL 1023
Adafruit_NeoPixel pixels(12, 7, NEO_GRB + NEO_KHZ800);

int joyX;
int joyY;
int joySW;

void setup() {
  pixels.begin();
  pixels.setBrightness(50);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  joyX = analogRead(A0);
  joyY = analogRead(A1); 
  joySW = analogRead(8);
  if (joyY=0){
    pixels.setPixelColor(12, red);
  }
}
