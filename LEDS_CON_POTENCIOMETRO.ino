int LED = 5;
int LED1 = 3;
int LED2 = 6;
int POT = 0;
int BRILLO;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

}

void loop() {
  BRILLO = analogRead (POT);
  if(BRILLO >=0 && BRILLO <=255){
    digitalWrite(LED, HIGH);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2,LOW);
    
  }

  if(BRILLO >=256 && BRILLO <= 680){
    digitalWrite(LED, LOW);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
  }
  if (BRILLO >=681 && BRILLO <=1023){
    digitalWrite(LED, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
  }
  
}
