int potenciometroPinX = A0;
int potenciometroPinY = A1;  
int valorLidoX = 0;
int valorLidoY = 0;

void setup() {
  Serial.begin(9600);       
}

void loop() {
  valorLidoX = analogRead(potenciometroPinX); 
  
  Serial.print("X: "); 
  Serial.println(valorLidoX);
  
  valorLidoY = analogRead(potenciometroPinY);
  
  Serial.print("Y: "); 
  Serial.println(valorLidoY);
  
  Serial.println("\n");
  delay(1000);
}
