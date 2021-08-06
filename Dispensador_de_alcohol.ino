#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

#include <Servo.h>
#define trigPin 2
#define echoPin 3
Servo servo;
int LEDR = 7;
int LEDV = 8;

void setup() {
 Serial.begin (9600);
 pinMode (trigPin, OUTPUT);
 pinMode (echoPin, INPUT);
 servo.attach(4);
 servo.write(0);
 digitalWrite (LEDR , LOW);  //Definimos la salida digital 7 con un estado bajo
 digitalWrite (LEDV , LOW);  //Definimos la salida digital 8 con un estado bajo
 lcd.init();
 lcd.backlight();
 lcd.setCursor(0, 0);
 lcd.print (" Cuida Tu Vida ");
 lcd.setCursor(0, 1);
 lcd.print (" Contra El Virus ");
  
}

void loop() {
  lcd.display ();
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(4);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(25);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
   

  if (distance <= 8) {
     digitalWrite (LEDR , HIGH);     //Si el sensor detecta una distancia menor a 20 cm enciende el LED Rojo
     digitalWrite (LEDV , LOW);  // y apaga el verde
     servo.write(140);
     lcd.setCursor(0, 0);
     lcd.print (" Tu Vida Vale ");
     lcd.setCursor(0, 1);
     lcd.print (" Alcohol Abierto ");
     delay(110);
       
  }
 else{    // de lo contrario
        digitalWrite (LEDR , LOW); //apaga el rojo
        lcd.setCursor(0,0);
        lcd.print (" Cuida Tu Vida ");
        lcd.setCursor(0, 1);
        lcd.print (" Contra El Virus ");
        servo.write(0);
        delay(500);
        digitalWrite (LEDV , HIGH);   //enciende el verde
       }
}
