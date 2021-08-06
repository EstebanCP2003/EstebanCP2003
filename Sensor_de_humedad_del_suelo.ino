

void setup() {
  pinMode(2,OUTPUT);
 Serial.begin(9600);

}

void loop() {
digitalWrite(2,LOW);
int lectura = analogRead (A0);
Serial.println(lectura);

if (lectura > 900){
Serial.println("Activar motor");
digitalWrite (2,HIGH);
delay(5000);

}
else{
  Serial.println("Humedad correcta");
  delay(2000);
}
//Serial.println("Desactivar motor");
digitalWrite(2,LOW);


}
