int sensorPin = 2;
int sensorState = 0;

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h> 
#include <Fonts/FreeMono9pt7b.h> 
#include <Fonts/FreeSansBoldOblique9pt7b.h>
#include <Fonts/FreeMonoOblique9pt7b.h>

#define OLED_RESET -1 

#define pinSensorIR 7

Adafruit_SH1106 display(OLED_RESET);

void setup() 
{

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

  display.setCursor(2,20); 

  if (sensorState == LOW) {

     display.setFont(&FreeMonoOblique9pt7b);

     display.setTextColor(WHITE);

     display.setTextSize(1);

     display.setCursor(2,15); 

     display.print("Ima");

     display.setCursor(2,40);

     display.print("detectado!");

     delay(1000);

     Serial.println("Ima detectado!");
  } 
else {
    Serial.println("No magnet detected.");

    display.setFont(&FreeMonoOblique9pt7b);

     display.setTextColor(WHITE);

     display.setTextSize(1);

     display.setCursor(2,15); 

     display.print("Nenhum ima detectado.");

     delay(1000);

    Serial.println("Nenhum ima detectado.");
}

display.display();

delay(500);

}