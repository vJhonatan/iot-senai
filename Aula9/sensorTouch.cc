const int pinoSensor = 2; 
const int pinoLed = 13;
 
void setup() {
  pinMode(pinoSensor, INPUT); 
  pinMode(pinoLed, OUTPUT); 
}
 
void loop() {
  if (digitalRead(pinoSensor) == HIGH){ 
    digitalWrite(pinoLed, HIGH); 
  }
  else{
    digitalWrite(pinoLed,LOW);
  } 
  delay(200); 
}