#include <DHT.h>
#include <DHT_U.h>

int  LED = 5;
int SENSOR = 2;
float Temperatura;
int Humedad;
DHT dht(SENSOR,DHT11);

void setup() {
 Serial.begin(115200);
 pinMode(2,INPUT);
 pinMode(5,OUTPUT);
 dht.begin();
}

void loop() 
{
  Temperatura= dht.readTemperature();
  Humedad= dht.readHumidity(); 
 Serial.print("El dato leido de la temperatura es:");
  Serial.println(Temperatura);
  Serial.print("El dato leido de humedad es:");
  Serial.println(Humedad);            
  delay(3000);

  if (Temperatura<33){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite (LED, LOW);
  }

}
