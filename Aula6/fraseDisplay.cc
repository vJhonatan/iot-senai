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
  display.setFont(&FreeMonoOblique9pt7b); 
  display.setTextColor(WHITE); 
  display.setTextSize(0);
  display.setCursor(10, 35); 
  display.print("8 + 8 = 16"); 

  display.drawRect(0, 0, 128, 64, WHITE);
  display.display();
}