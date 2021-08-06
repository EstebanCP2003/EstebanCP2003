void setup() {
 pinMode (6, OUTPUT);
}

void loop() {
   for(int x=0;x<30;x++)
   {
    digitalWrite(6,HIGH);
    delay(40);
    digitalWrite(6,LOW);
    delay(40);
   }
   digitalWrite(6,LOW);
   delay(1000);
}
