int x;
void setup() {
  pinMode(6, OUTPUT);

}

void loop() {
  for(int x=0; x<255;x++)
  {
    analogWrite(6,x);
    delay(2);
    
  }
 for(int x=254;x>1;x--)
 {
   analogWrite(6,x);
  delay(2);
 }
}
