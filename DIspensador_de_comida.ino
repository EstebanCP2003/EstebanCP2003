#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C pantallita (0x27, 16, 2);

#include <ThreeWire.h>
#include <RtcDS1302.h>

ThreeWire mywire (4,5,2); //Declaramos los pines del modulo RTC 1302
RtcDS1302<ThreeWire> Rtc(mywire);

int Hora;
int Minuto;
int Segundo;

void setup() 
{
   Serial.begin(57600);

    Serial.print("compiled: ");
   //Serial.print(__DATE__);
    //Serial.println(__TIME__);
    
    pantallita.begin(16,2);
    pantallita.init();
    pantallita.backlight();
    
    Rtc.Begin();

   RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    printDateTime(compiled);
    Serial.println();
}

void loop() 
{
 RtcDateTime now = Rtc.GetDateTime();

    printDateTime(now);
    Serial.println();

    if (!now.IsValid())
    {
    Serial.println ("ERROR EN FECHA Y HORA");
    }
    delay(1000);
  
}

#define countof(a) (sizeof(a) / sizeof (a[0]))

void printDateTime (const RtcDateTime& dt)
{
  char datestring[20];

    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Month(),
            dt.Day(),
            dt.Year(),
          Hora == dt.Hour(),
          Minuto== dt.Minute(),
          Segundo==dt.Second());
          
 if(Minuto >59){
  Minuto == 00;
    pantallita.setCursor(11,1);
     pantallita.print("  ");

     if(Minuto >9){
     pantallita.setCursor(11,1);
     pantallita.print(' ');
     }
 }
 
     pantallita.setCursor(0,0);
     pantallita.print("Fecha:");
     pantallita.print(dt.Month());
     pantallita.print("/");
     pantallita.print(dt.Day());
     pantallita.print("/");
     pantallita.print(dt.Year());
    // pantallita.setCursor(0,14);
    // pantallita.print(" ");
     pantallita.setCursor(0,1);
     pantallita.print("Tiempo:");
     pantallita.print(dt.Hour());
     pantallita.setCursor(9,1);
     pantallita.print(":");
     pantallita.print(dt.Minute());
     pantallita.setCursor(12,1);
     pantallita.print(":");
     pantallita.print(dt.Second());
    // Serial.print(datestring);
    //Primer accionamiento de comida
  /*  if(Hora == 22 && Minuto == 35 && Segundo == 10){
      
    }

    if (Hora == 22 && Minuto == 35 && Segundo == 20){
    
    }
    //Segundo accionamiento de comida
    /* if(Hora == 22 && Minuto == 30 && Segundo == 10){
   servo1.write(180);
    }
     if (Hora == 22 && Minuto == 30 && Segundo == 20){
      servo1.write(0);
    }*/
}
