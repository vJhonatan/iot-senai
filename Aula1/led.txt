int led = 13;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led,1);
  delay(1500);
  digitalWrite(led, 0);
  delay(500);
}
