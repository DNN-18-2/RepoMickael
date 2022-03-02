#include <Adafruit_NeoPixel.h>
int DataIn = 12;
int i;
Adafruit_NeoPixel pixels(12, 7, NEO_GRB + NEO_KHZ800);

int VRx = A0;
int VRy = A1;
int SW = 8;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

void setup() {
  pixels.begin();
  pixels.setBrightness(50);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
}
 
void loop() {
    xPosition = analogRead(VRx);
    yPosition = analogRead(VRy);
    SW_state = digitalRead(SW);
    mapX = map(xPosition, 0, 1023, -512, 512);
    mapY = map(yPosition, 0, 1023, -512, 512);

    {

  readmapX ();
  delay(100);

}
{

  readmapY ();
  delay(100);

}
  if ((mapX>=-515)&& (mapX<=-510)&&(mapY>=-175)&& (mapY<=-168))
 for (i = 0; i<=12; i++) {
   pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    pixels.show();
    }
  if ((mapX>=168)&& (mapX<=175)&&(mapY>=-175)&& (mapY<=-168))
  for (i = 0; i<=12; i++) {
   pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
    }
  if ((mapX<=-166)&& (mapX>=-175)&&(mapY>=-515)&& (mapY<=-510))
  pixels.setPixelColor(6, pixels.Color(10, 0, 0));
  pixels.show();
  if ((mapX>=-175)&& (mapX<=-170)&&(mapY>=165)&& (mapY<=175))
  pixels.setPixelColor(8, pixels.Color(10, 10, 10));
  pixels.show();
  if (SW_state==0)
  for (i = 0; i<=12; i++) {
   pixels.setPixelColor(i, pixels.Color(0, 44, 255));
    pixels.show();
    }
   if (SW_state==1)
  for (i = 0; i<=12; i++) {
   pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
    }
  delay(300);
}
