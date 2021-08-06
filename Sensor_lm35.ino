
int dato;
int temperatura;

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  

}

void loop() {
  //Rango de voltaje de Arduino ==> 0 a 5v ==> en ml V ==> 0 a 5000
  //Rango del sensor lm35 0 a 1023
  // S                 A
 //  0                 0
 // 1023               5000.0
 // dato               x
//Temperatura = (dato * 5000)/1023)10

dato = analogRead (A0);
temperatura = map(dato,0,1023,2,150);
Serial.println (temperatura);
delay(500);
}
