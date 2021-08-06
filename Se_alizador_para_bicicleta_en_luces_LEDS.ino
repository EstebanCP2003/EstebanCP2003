void setup() {
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);

}

void loop() {
  int data= analogRead (A0);
  if(data>900)
  {
    digitalWrite(5, HIGH);
    delay(100);
    digitalWrite(5, LOW);
    delay(100);
  }
  data= analogRead (A0);
  if(data<100)
  {
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(100);
}
}
