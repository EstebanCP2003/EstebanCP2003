void setup() {
  pinMode(2, OUTPUT);
  pinMode(A0, INPUT);
}
void loop() {
  if(analogRead(A0) > 600) {
    digitalWrite(2, !digitalRead(2));
    delay(1000);
  }
}
