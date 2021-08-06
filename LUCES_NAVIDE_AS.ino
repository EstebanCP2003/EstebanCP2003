void setup() {
 pinMode(2, OUTPUT); 
 pinMode(3, OUTPUT); 
 pinMode(4, OUTPUT); 
 pinMode(5, OUTPUT); 
 pinMode(6, OUTPUT);   

}
void loop() {
  for(int x=2;x<6;x++)
  {
    digitalWrite(x, HIGH);
    delay(80);
    digitalWrite(x,LOW);
    delay(80);
  }
 for(int x=2;x<6;x++)
  {
    digitalWrite(x, HIGH);
    delay(90);
    digitalWrite(x,LOW);
    delay(90);
  }

}
