// Buttons

int button = 0;

// Semaforo

int red = 1;
int yellow = 2;
int green = 3;

void setup()
{
  pinMode(13, INPUT);
  
  pinMode(red, OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
}

void loop()
{
  button = digitalRead(13);

  if(button == 1){
      digitalWrite(red, 1);
      delay(2000);

      digitalWrite(red,0);
      digitalWrite(green,1);
      delay(3000);

      digitalWrite(green,0);
      digitalWrite(yellow,1);
      delay(1000);

      digitalWrite(yellow,0);
  }else {
      digitalWrite(red,0);
      digitalWrite(yellow,0);
      digitalWrite(green,0);
  }
}