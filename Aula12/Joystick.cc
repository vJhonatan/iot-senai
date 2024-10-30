#include <Wire.h>

#include <LiquidCrystal_I2C.h> // Biblioteca para LCD I2C

const int pinButton = 2; // Pino do botão

const int centerThreshold = 100; // Limite para considerar que está no centro

const int moveThreshold = 100; // Limite para considerar movimento

LiquidCrystal_I2C lcd(0x3F, 16, 2); // 16 colunas e 2 linhas


void setup() {

  Serial.begin(9600);

  pinMode(pinButton, INPUT_PULLUP);

  lcd.init();

  lcd.backlight();

}


void loop() {


  int valueX = analogRead(A0);

  int valueY = analogRead(A1);

  int buttonState = digitalRead(pinButton);

  String direction = "Centro";


  if (valueX < 512 - moveThreshold) {

    direction = "Esquerda";

  } else if (valueX > 512 + moveThreshold) {

    direction = "Direita";

  }

  if (valueY < 512 - moveThreshold) {

    direction = "Cima";

  } else if (valueY > 512 + moveThreshold) {

    direction = "Baixo";

  }

  lcd.clear();

  lcd.setCursor(0, 0);

  lcd.print("Direcao: ");

  lcd.print(direction);


  lcd.setCursor(0, 1);

  lcd.print("Botao: ");

  lcd.print(buttonState == LOW ? "Pressionado" : "Solto");


  delay(1000);

}