void setup() {
 
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);

}

void loop() {

  for(int x=0;x<20;x++)
  {
    digitalWrite(5, HIGH);
    delay(40);
    digitalWrite(5, LOW);
    delay(40);
  }
for(int x=0;x<20;x++)
  {
    digitalWrite(6, HIGH);
    delay(40);
    digitalWrite(6, LOW);
    delay(40);
  }
}
