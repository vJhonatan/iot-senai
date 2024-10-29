#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeSansBoldOblique9pt7b.h>
#include <Fonts/FreeMonoOblique9pt7b.h>

const int sensorPin = 10;
int sensorState = 0;

#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET);

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
}

void loop() {
  sensorState = digitalRead(sensorPin);
  display.clearDisplay();

  display.setFont(&FreeMonoOblique9pt7b);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(2, 15);

  if (sensorState == LOW) {
    display.print("Som detectado!");
    Serial.println("Som detectado!");
  } else {
    display.print("Nenhum som detectado.");
    Serial.println("Nenhum som detectado.");
  }

  display.display();
}
