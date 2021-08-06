#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>

LiquidCrystal_I2C lcd (0x27,16,2);

int LedR = 4;  //LED ROJO
int LedA = 5; // LED AZUL 
int Rele = 3;  //MOTOR
int Sensorpin = A0; //SENSOR DE HUMEDAD DE TIERRA
int SENSOR = 2; // SENSOR DHT 11
float Temperatura; // VARIABLE DEL DHT 11
//int Humedad;
DHT dht(SENSOR,DHT11);

void setup() {
 Serial.begin(9600);
 pinMode(LedR,OUTPUT);
 pinMode(LedA,OUTPUT);
 pinMode(6,INPUT);
 pinMode(2,INPUT);
 dht.begin();
 lcd.init();
 lcd.backlight();
}

void loop() {
  //digitalWrite(LedR,HIGH);
  //digitalWrite(LedA,LOW);
  int humedad=analogRead(Sensorpin); // SE LEE EL VALOR DEL SENSOR 
  lcd.setCursor(0,0);
  lcd.print("H: ");
  lcd.setCursor(2,0);
  lcd.print(humedad);
  delay(1000);
  
   if(humedad >=1010)
 {
    digitalWrite(LedR, LOW);
    digitalWrite(Rele,HIGH);
    digitalWrite(LedA,HIGH);
 }
  else if (humedad <=400)
 {
    digitalWrite(LedR, HIGH);
    digitalWrite(Rele,LOW);
    digitalWrite(LedA,LOW);
 }
Temperatura= dht.readTemperature();  //LECTURA DEL SENSOR DHT 11
 lcd.setCursor(0,1);
  lcd.print("T: ");
  lcd.setCursor(2,1);
  lcd.print(Temperatura);
 delay(3000);



 }
