int Sensorpin = A0;

void setup() {
  Serial.begin(9600);

}

void loop() {
 int humedad= analogRead(Sensorpin);
 Serial.println(humedad);
 delay(1000);

}
