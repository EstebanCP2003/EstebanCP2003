#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27,16,2);

int horas = 0;
int minutos = 0;
int segundos = 0;
int segundostotal = 0;

#define pulsahora 12
#define pulsamin  11
#define pulsaseg  10 
#define iniciar   9 
#define buzzer   6 
#define rele   5

int varpulsahora = 0;
int varpulsamin = 0;
int varpulsaseg = 0;

void setup()
{

 pinMode (pulsahora, INPUT);     // PIN DEL PULSADOR DE HORAS
 pinMode (pulsamin, INPUT);      // PIN DEL PULSADOR DE MINUTOS
 pinMode (pulsaseg, INPUT);      // PIN DEL PULSADOR DE SEGUNDOS
 pinMode (iniciar, INPUT);      // PIN DEL PULSADOR DE INICIO 
 pinMode (rele, OUTPUT);
 pinMode (buzzer, OUTPUT);
 lcd.begin (16, 2);
 lcd.init();
 lcd.backlight();
 lcd.clear();

 lcd.setCursor (2,0);               // MENSAJE DE BIENVENIDA 
 lcd.print("TEMPORIZADOR");
 lcd.setCursor (0,1);
 lcd.print ("WELCOME ESTEBAN");
 delay (2000);
 lcd.clear();
 digitalWrite(buzzer, HIGH);
 delay (400);
 digitalWrite (buzzer, LOW);
 
}

 void loop ()
 
{
   
  while(digitalRead(iniciar) == 0)
  {
    varpulsahora = digitalRead(pulsahora);      //Leeremos el pulsador de horas
    varpulsamin = digitalRead (pulsamin);       //Leeremos el pulsador de minutos 
    varpulsaseg = digitalRead (pulsaseg);       //Leeremos el pulsador de segundos 

    if(varpulsahora == HIGH)                         // Si el boton ha sido pulsado, aumentamos los minutos en unidad
  {
    horas = horas + 1;
    if(horas == 24)
    horas = 0;
    delay (200);
   }

    if(varpulsamin == HIGH)                         // Si el boton ha sido pulsado, aumentamos los minutos en unidad
  {
    minutos = minutos + 1;
    if(minutos == 60)
    minutos = 0;
    delay (200);
   }

    if(varpulsaseg == HIGH)                         // Si el boton ha sido pulsado, aumentamos los segundos en unidad
  {
    segundos = segundos + 1;
    if(segundos == 60)
    segundos = 0;
    delay (200);
   }
   lcd.setCursor(0,0);
   lcd.print ("ELIGE EL TIEMPO");
   lcd.setCursor(4,1);

   if (horas < 10)
   lcd.print ("0");                         // Si los minutos son menor que 10, pone un "0" delante.
   lcd.print(horas);
   lcd.print(":");

   if (minutos < 10) 
   lcd.print ("0");                         // Si los minutos son menor que 10, pone un "0" delante.
   lcd.print(minutos);
   lcd.print(":");

  if (segundos < 10)
   lcd.print ("0");                         // Si los segundos son menor que 10, pone un "0" delante.
   lcd.print(segundos);
  
 }
   lcd.clear();
   delay(100);
   segundostotal = segundos+(minutos*60) + (horas*60*60);         //Convertimos el tiempo elegido en segundos 
   
  while (segundostotal>0)
  {

      segundostotal--;
      horas = (segundostotal/ 3600);        //Convertimos los segundos totales en horas 
      minutos = (segundostotal / 60) % 60;      //Convertimos los segundos totales en minutos 
      segundos = segundostotal % 60;       //Convertimos los segundos totales en periodos de 60 segundos 

      lcd.setCursor(0,0);
      lcd.print ("TIEMPO RESTANTE:");
      digitalWrite(rele,HIGH);
      delay (1000);
      lcd.setCursor(4,1);

     if (horas < 10)
   {
     lcd.print ("0");
     lcd.print (horas);
     lcd.print(":");

     if (minutos < 10)
     lcd.print ("0");
     lcd.print (minutos);
     lcd.print(":");


    if (segundos < 10)
     lcd.print ("0");
     lcd.print (segundos);
     
    if (segundostotal == 0)
   {
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("TIEMPO");            // Mensaje de Finalización del proceso 
    lcd.setCursor(3,1);
    lcd.print("FINALIZADO");
    digitalWrite(buzzer,HIGH);
    digitalWrite(rele,LOW);
    delay(2000);
    digitalWrite(buzzer,LOW);
    lcd.clear();
    delay(200);
    
  }
}
  }
}
