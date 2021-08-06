#include <Ticker.h>
#include <ESP8266WiFi.h>

#define ledWifi 5

String ssid = "187e8c226765";
String password= "4aca7182b159";
Ticker tic_WifiLed;

byte cont = 0;
byte max_intentos = 50;

void parpadeoLedWifi(){
  byte estado = digitalRead(ledWifi);
  digitalWrite(ledWifi,!estado);
}

void setup() {
 //INICIA SERIAL
 pinMode(ledWifi, OUTPUT);
 Serial.begin(115200);
 Serial.println("\n");
//conexion wifi
tic_WifiLed.attach(0.2,parpadeoLedWifi);
 WiFi.begin(ssid, password);
 while(WiFi.status()!=WL_CONNECTED and cont <max_intentos){ //Cuenta hasta 50
  cont ++;
  delay(500);
  Serial.print(".");
 }
Serial.println("");

if (cont < max_intentos){//si se conectò
  Serial.println("********************************************");
  Serial.print("Conectado a la red wifi: ");
  Serial.println(WiFi.SSID());
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("macAdress:  ");
  Serial.println(WiFi.macAddress());
  Serial.println("*********************************************");
}
else{//No se conectò
  Serial.println("---------------------------------------------");
  Serial.println("Error de conexion");
  Serial.println("---------------------------------------------");
}

tic_WifiLed.detach();
digitalWrite(ledWifi,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}
