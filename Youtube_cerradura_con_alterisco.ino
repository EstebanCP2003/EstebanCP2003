#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const byte ROWS = 4; // Cuatro Filas
const byte COLS = 4; // Cuatro Columnas

LiquidCrystal_I2C lcd(0x3F,16,2); //Definimos los pines del LCD
char A; 
char B[4]; 
char C[6]= "0504A"; // CLAVE
byte D = 0; 
int E = 0;
int ledGreen = 13;

// Definimos el Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = { 9,8,7,6 }; // Pines conectados al Arduino
byte colPins[COLS] = { 5,4,3,2,}; // Pines conectados al Arduino

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup(){
  lcd.begin(16, 2);
  digitalWrite(ledGreen, LOW);
  pinMode(13, OUTPUT);
}
void loop(){
  A = keypad.getKey();
  if(A){
    B[D]= A;
    D ++;
  }
  if(D==0){
    lcd.setCursor(0,0);
    lcd.print( "DIGITE SU CLAVE" );
  }
  if(D==1){
    lcd.setCursor(0,1);
    lcd.print( "*_" );
  }
  if(D==2){
    lcd.setCursor(0,1);
    lcd.print( "**_" );
  }
  if(D==3){
    lcd.setCursor(0,1);
    lcd.print( "***_" );
  }
  if(D==4){
    lcd.setCursor(0,1);
    lcd.print( "****" );
  }
 if((D>6) && (D ='A')){
    if(!strcmp(B,C)){
      lcd.setCursor(0,0);
      lcd.print("CLAVE CORRECTA  ");
      delay(1000);
      digitalWrite(ledGreen, HIGH);
      delay(1000);
      D=0;
      E=0;
      lcd.setCursor(0,1);
      lcd.print("             ");
    }
    else
    {
      lcd.setCursor(0,0);
      lcd.print("Error        ");
      delay(1000);
      E++;
      D=0;
    }
  }

  
    if(E==3){
    lcd.setCursor(0,0);
     lcd.print("SISTEMA         ");
    lcd.setCursor(0,1);
     lcd.print("BLOQUEADO ");
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
    lcd.setCursor(0,1);
     lcd.print("             ");
     D=0;
     E=0;
  }
}
