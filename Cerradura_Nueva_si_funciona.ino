#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Wire.h>
Servo servo;


LiquidCrystal_I2C lcd(0x27,16,2);
//Matriz del KeyPad 4x4
const byte Filas = 4;  //Cuatro filas
const byte Cols = 4;   //Cuatro columnas
byte Pins_Filas[] = {9,8,7,6};//Pines de Arduino a las filasbyte 
byte Pins_Cols[] = {5,4,3,2}; // Pines de Arduino a las columnas.
//no se utilizan los pines 1 y 0 para no interferir en Rx y Tx


//Definimos el teclado
char Teclas [ Filas ][ Cols ] =
 {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
 };

const int CantDigClave = 4; //Tamaño de la clave
char codigoSecreto[CantDigClave] = {'2','8','4','2'}; // Aqui va el codigo secreto

int posicion=0;    // necesaria para la clave
int cursor=5;      // posicion inicial de la clave en el LCD
int clave=0;       // Valor para indicar que la clave es correcta, 0 = incorrecta, 1 = Correcta
int ledVerde=12;   // pin para el LED verde
int ledRojo=11;    // pin para el LED rojo
int buzzer=10;     // pin altavoz
int cont=0;      // Contador de errores
const int buttonPin = A0;
int val;
int buttonState = 0;



  // Create the Keypad

  Keypad teclado = Keypad(makeKeymap(Teclas), Pins_Filas, Pins_Cols, Filas, Cols);

  void setup() 

  {
      Serial.begin(9600) ;
      lcd.begin(16,2);       // inicializamos el LCD.
      pinMode (ledVerde,OUTPUT);
      pinMode (ledRojo, OUTPUT);
      pinMode (buzzer, OUTPUT);
      digitalWrite(ledRojo,HIGH); // encendemos el LED rojo
      digitalWrite(ledVerde, LOW); // apagamos el verde
       lcd.init();
       lcd.backlight();
      lcd.setCursor(0,0);     // situamos el cursor el la posición 0 de la linea 0.
      lcd.print("ENTER PASSWORD"); // escribimos en LCD
      lcd.setCursor(cursor,1); // cursor en la posicion de la variable, linea 1
      lcd.print("_a__"); // borramos de la pantalla los numeros   
      lcd.setCursor(cursor,1); // cursor en la posicion de la variable, linea 1
    servo.attach (13);
    servo.write(0);  
     pinMode(buttonPin, INPUT);   
  }

  void loop() 

  {
      char pulsacion = teclado.getKey() ; // leemos pulsacion
      //lcd.setCursor(0, 1);
      if (pulsacion != 0) //Si el valor es 0 es que no se ha pulsado ninguna tecla
        { // descartamos almohadilla y asterisco
          if (pulsacion != '#' && pulsacion != '*' && clave==0)
           { 
            if(pulsacion!= 1){
            lcd.print("*"); // imprimimos pulsacion
             cursor++;             // incrementamos el cursor
             tone(buzzer,900);     // tono de pulsacion
             delay(200);
             noTone(buzzer);
             }

      //--- Condicionales para comprobar la clave introducida -----------
      // comparamos entrada con cada uno de los digitos, uno a uno
      if (pulsacion == codigoSecreto[posicion])
          posicion ++; // aumentamos posicion si es correcto el digito

      if (posicion == CantDigClave)
       { // comprobamos que se han introducido los 4 digitos correctamente
         lcd.setCursor(0,0);      // situamos el cursor el la pos 0 de la linea 0.
         lcd.print("WELCOME ESTEBAN");// escribimos en LCD     
         delay(200);
         // tono de clave correcta
         tone(buzzer,1000);
         delay(200);
         noTone(buzzer);
         tone(buzzer,1200);
         delay(200);
         noTone(buzzer);
         tone(buzzer,1500);
         delay(200);
         noTone(buzzer);

         lcd.setCursor(0,1); // cursor en la posicion 0, linea 1
         lcd.print("  tiene 10 seg   ");            
         clave=1; // indicamos que la clave es correcta
         digitalWrite(ledRojo,LOW); // apagamos el LED rojo
         digitalWrite(ledVerde, HIGH); // encendemos el verde
         servo.write(90);
         
         delay(6000);//seteamos que esperara solo 6 segundos para volver a cerrar el sistema
         clave=0; // indicamos que se ha borrado la clave
         cursor=5;
         posicion=0;
         digitalWrite(ledVerde, LOW); // Apagamos el verde         
         digitalWrite(ledRojo,HIGH); // Encendemos el LED rojo
         servo.write (0);
         lcd.init();
         lcd.setCursor(1,0);     // situamos el cursor el la posición 0 de la linea 0.
         lcd.print("ENTER PASSWORD"); // escribimos en LCD
         lcd.setCursor(0,1); // cursor en la posicion 0, linea 1
         lcd.print("     ____     "); // borramos de la pantalla los numeros
         lcd.setCursor(5,1);
         cont=0;//reseteamos el contador de errores         

     }
            
     //--- En el caso de que este incompleta o no hayamos acertado ----------
     if(cursor>8)        // comprobamos que no pase de la cuarta posicion
       {   cursor=5;     // lo volvemos a colocar al inicio
           posicion=0;           // borramos clave introducida
           lcd.setCursor(5,1);
           lcd.print("____");  // borramos la clave de la pantalla          
           lcd.setCursor(5,1);      
           if(clave==0)         // comprobamos que no hemos acertado
              { tone(buzzer,70,500.900); // para generar tono de error
                delay(250); 
                noTone(buzzer);
                cont++;//Aumentamos contador de errores
                lcd.init();
                lcd.setCursor(4,0);     // situamos el cursor el la posición 0 de la linea 0.
            lcd.print("INCORRECT"); // escribimos en LCD
              delay(3000);//tiempo de espera de 3 segundos
               lcd.setCursor(0,0);     // situamos el cursor el la posición 0 de la linea 0.
            lcd.print("ENTER PASSWORD"); // escribimos en LCD
                lcd.setCursor(5,1); // cursor en la posicion 0, linea 1
                 lcd.print("____");  // borramos la clave de la pantalla          
           lcd.setCursor(5,1);
              }
               
              
          
        Serial.println(cont);
        //Si acaso la cantidad de errores es igual a 3 se activará la alarma sonora
          if(cont==3)
          {
            tone(buzzer,800,500);//Tono de Alarma
             cont=0;//reseteamos el contador de errores
            lcd.init();
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("SYSTEM LOCKED");
            lcd.setCursor(2,1);
            lcd.print("Tiemp0 R:");
            lcd.setCursor(11,1);
           lcd.print("10");
     delay(1000);
    lcd.setCursor(11,1);
     lcd.print("09");
     delay(1000);
    lcd.setCursor(11,1);
     lcd.print("08");
     delay(1000);
    lcd.setCursor(11,1);
     lcd.print("07");
     delay(1000);
    lcd.setCursor(11,1);
     lcd.print("06");
     delay(1000);
    lcd.setCursor(11,1);
     lcd.print("05");
     delay(1000);lcd.setCursor(11,1);
     lcd.print("04");
     delay(1000);
    lcd.setCursor(11,1);
     lcd.print("03");
     delay(1000);
    lcd.setCursor(11,1);
     lcd.print("02");
     delay(1000);
    lcd.setCursor(11,1);
     lcd.print("01");
     delay(1000);
    lcd.setCursor(11,1);
     lcd.print("00");
     delay(1000);
            
           
             lcd.init();
             lcd.clear();
              lcd.setCursor(1,0);     // situamos el cursor el la posición 0 de la linea 0.
         lcd.print("ENTER PASSWORD"); // escribimos en LCD
         lcd.setCursor(0,1); // cursor en la posicion 0, linea 1
         lcd.print("     ____     "); // borramos de la pantalla los numeros
         lcd.setCursor(5,1);
          }        
        }
     }
   } 
        buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {     
    val = 160;
    servo.write (90);
    digitalWrite (ledVerde, HIGH);
     digitalWrite (ledRojo, LOW);
    lcd.init();
    lcd.setCursor (5,0);
    lcd.print (" EXIT ");
    delay(10000);
     digitalWrite (ledRojo, HIGH);
     digitalWrite (ledVerde, LOW);
    servo.write (0);
     posicion = 0;
       cursor = 5;
       clave=0;
       posicion=0;
       lcd.setCursor(0,0); // situamos el cursor el la posición 2 de la linea 0.
       lcd.print("ENTER PASSWORD"); // escribimos en LCD
       lcd.setCursor(5,1);
       lcd.print("____"); // borramos de la pantalla los numeros
       lcd.setCursor(5,1);
  }
  }
  
 
