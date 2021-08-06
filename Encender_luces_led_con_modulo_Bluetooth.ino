#include <SoftwareSerial.h>

SoftwareSerial miBT(10,11);
char Dato = 0;
int LED1 = 2;
int LED2 = 3;
int Rele = 4;
int Brillo = 0;
void setup() {
  Serial.begin(9600);
Serial.println("Listo");
miBT.begin(38400);//38400
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(Rele,OUTPUT);
digitalWrite(Rele,HIGH);
}

void loop() {
 if(miBT.available()){
  Dato=miBT.read();
  if (Dato == '1')
  digitalWrite(LED1,!digitalRead(LED1));

  //if (Dato == '2')
 //digitalWrite(LED2,!digitalRead(LED2));

  if (Dato == '2'){
    Brillo = Brillo + 10;
    if(Brillo >255)
    Brillo = 255;
    analogWrite(LED2,Brillo);
  }
   if(Dato =='3'){
   Brillo = Brillo - 10;
   if(Brillo < 0)
   Brillo = 0;
   analogWrite(LED2,Brillo);
 }
 if( Dato == '4')
   
 digitalWrite(Rele,!digitalRead(Rele)
 
 
 );
 }
}
