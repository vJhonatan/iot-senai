#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_I2C_ADDRESS 0x3C // Endereço I2C do display OLED

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Definindo a senha
const String senhaCorreta = "123456";
String senhaDigitada = "";
const int buttonPins[6] = {2, 3, 4, 5, 6, 7}; // Pinos onde os botões estão conectados
const int numButtons = 6;

void setup() {
  // Inicializando o display OLED
  display.begin(OLED_I2C_ADDRESS, OLED_RESET); // Usando OLED_I2C_ADDRESS aqui
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  
  // Configurando os pinos dos botões
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT);
  }
}

void loop() {
  for (int i = 0; i < numButtons; i++) {
    if (digitalRead(buttonPins[i]) == HIGH) { // Se o botão for pressionado
      senhaDigitada += String(i + 1); // Adiciona o número da tecla pressionada
      mostrarSenha();

      // Verifica se a senha tem 6 dígitos
      if (senhaDigitada.length() == 6) {
        verificarSenha();
      }
      
      delay(200); // Debounce
    }
  }
}

void mostrarSenha() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("SENHA");
  display.println(senhaDigitada);
  display.display();
}

void verificarSenha() {
  display.clearDisplay();
  display.setCursor(0, 0);
  
  if (senhaDigitada == senhaCorreta) {
    display.println("SENHA CORRETA");
  } else {
    display.println("SENHA INCORRETA");
  }
  
  display.display();
  senhaDigitada = ""; // Reseta a senha digitada
  delay(2000); // Exibe a mensagem por 2 segundos
}