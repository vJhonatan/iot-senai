int potenciometroPinX = A0;  
int potenciometroPinY = A1;
int valorLidoX = 0;
int valorLidoY = 0;

void setup() {
  Serial.begin(9600);     
}

void loop() {
  // Y Vertical
  valorLidoY = analogRead(potenciometroPinY);
  
  if (valorLidoY < 160 || valorLidoY > 800) { 
    Serial.print("Y = ");
    Serial.print(valorLidoY);
    Serial.println(". Para baixo");
} else {  
    Serial.print("Y = ");
    Serial.print(valorLidoY);
    Serial.println(". Para cima");
 }


  // X Horizontal
  valorLidoX = analogRead(potenciometroPinX);  
  
  if (valorLidoX < 512) {  
    Serial.print("X = ");
    Serial.print(valorLidoX);
    Serial.println(". Para esquerda");
  } else {
    Serial.print("X = ");
    Serial.print(valorLidoX);
    Serial.println(". Para direita");
  }
  
  Serial.println(); 
  delay(1500);
}
