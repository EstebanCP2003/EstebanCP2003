#include <Servo.h>

Servo servo1; 

int PINSERVO = 2;
int trigger = 9;
int echo = 8;
int led = 13;
float tiempo_espera, distancia;

void setup() {
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode,(led,OUTPUT);
  servo1.attach(2);
 servo1.write(0);
}

void loop() {
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);

tiempo_espera = pulseIn(echo,HIGH);
distancia = (tiempo_espera/2)/29.15; // el 29.15 es la velocidad del sonido por centimetro por microsegundo.

Serial.println(distancia);
delay(300);

if(distancia <= 10){
  digitalWrite(led,HIGH);
     servo1.write(180);
     delay(110);
}
else{
  digitalWrite(led,LOW);
  servo1.write(0);
  delay(500);
}
}
