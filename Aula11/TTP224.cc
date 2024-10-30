const int sensorPin = 2; 
const int ledPins[] = {10, 11, 12, 13};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

int currentLED = 0; 

void setup() {
  pinMode(sensorPin, INPUT);  
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT); 
  }
}

void loop() {
  if (digitalRead(sensorPin) == HIGH) {
    currentLED = (currentLED + 1) % (numLeds + 1); 
    updateLEDs();
    delay(300); 
  }
}

void updateLEDs() {
  for (int i = 0; i < numLeds; i++) {
    if (i < currentLED) {
      digitalWrite(ledPins[i], HIGH); 
    } else {
      digitalWrite(ledPins[i], LOW);  
    }
  }
}