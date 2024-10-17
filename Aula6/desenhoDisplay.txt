#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#include <Fonts/FreeMono9pt7b.h> 
#include <Fonts/FreeSansBoldOblique9pt7b.h> 
#include <Fonts/FreeMonoOblique9pt7b.h> 

#define OLED_RESET -1

Adafruit_SH1106 display(OLED_RESET);

void setup() {
  Serial.begin(9600);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
}

void loop() {
  display.clearDisplay(); 

  display.drawRect(0, 0, 128, 64, WHITE);

  display.drawCircle(100, 20, 10, WHITE); 
  for (int i = 0; i < 360; i += 15) {
    int x1 = 100 + cos(radians(i)) * 15; 
    int y1 = 20 + sin(radians(i)) * 15;
    int x2 = 100 + cos(radians(i)) * 10;
    int y2 = 20 + sin(radians(i)) * 10;
    display.drawLine(x1, y1, x2, y2, WHITE); 
  }

  display.drawTriangle(0, 50, 30, 20, 60, 50, WHITE);
  display.drawTriangle(40, 50, 70, 10, 100, 50, WHITE);
  display.drawTriangle(90, 50, 120, 25, 128, 50, WHITE);

  display.display();
}
