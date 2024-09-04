int LDR = 0;
int LED = 9;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int LDR = analogRead(A0);
  Serial.print("\nValor lido pelo LDR = ");
  Serial.println(LDR);
  
  if (LDR > 650){
    digitalWrite(LED,HIGH); 
    Serial.print("\nLED Ligado!"); }
  else {
    digitalWrite(LED, LOW);
    Serial.print("\nLED Desligado!"); }
  
 delay(1000);
}