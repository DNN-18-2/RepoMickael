#include <Adafruit_NeoPixel.h>

#define LED_PIN    6
#define LED_COUNT 12
#define NUM_JOY 2
#define MIN_VAL 0
#define MAX_VAL 1023

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

struct color {
  byte R;
  byte G;
  byte B;
};

struct color cLed[LED_COUNT] = {255, 255, 255,
         255, 0, 0,
         0, 255, 0,
         0, 0, 255,
         255, 255, 0,
         0, 255, 255,
         255, 0, 255,
         160, 0, 160,
         120, 0, 120,
         80, 0, 80,
         40, 00, 40,
         255, 255, 0
};

//Parameters
const int joyBtn  = 2;

//Variables
//int joyVal [NUM_JOY] = {0, 0};
int joyX = 0;
int joyY = 0;


void setup() {
  //Init Joystick
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(joyBtn, INPUT_PULLUP);
  Serial.begin(38400);
  Serial.println("Début de la séquence de test...");
  strip.begin();
  strip.setBrightness(10);
  strip.fill();
  strip.show(); // Initialize all pixels to 'off'
  for (int i = 0; i <= 11; i++) {
    strip.setPixelColor(i, cLed[i].R, cLed[i].G, cLed[i].B);
    showDel(100);
  }
  int bright = 1;
  while (bright > 0) {
    bright = 0;
    for (int i = 0; i <= 11; i++) {
      if (cLed[i].R > 0) cLed[i].R--;
      if (cLed[i].G > 0) cLed[i].G--;
      if (cLed[i].B > 0) cLed[i].B--;
      bright = bright + cLed[i].R + cLed[i].G + cLed[i].B;
      strip.setPixelColor(i, cLed[i].R, cLed[i].G, cLed[i].B);
    }
    showDel(5);
  }
  Serial.println("...fin de la séquence de test");
}

void loop() {

  readJoystick();
  delay(500);

}

void showDel(int delais) {
  strip.show();
  delay(delais);
}

void readJoystick( ) { /* function readJoystick */
  ////Test routine for Joystick
 {
    joyX = analogRead(A0);
    joyY = analogRead(A1);
  }
  if (!digitalRead(joyBtn)) {
    Serial.println(F("Joy Button pressed"));
  }
}
