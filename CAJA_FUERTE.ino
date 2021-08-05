#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);
const byte Filas = 4; 
const byte Cols = 4;   
byte Pins_Filas[] = {9,8,7,6}; 
byte Pins_Cols[] = {5,4,3,2};

char Teclas [ Filas ][ Cols ] =
 {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
 };
const int Clave=6;
char codigoSecreto[Clave] = {'1','2','3','4','5','6'};
char pulsacion;
int posicion =0; int cursor=5; int clave=0; int buzzer=10; int contador=0; int chapa =12; int contador_tiempo =0;
int ledR = 11; int ledA=13;

Keypad teclado = Keypad(makeKeymap(Teclas), Pins_Filas, Pins_Cols, Filas, Cols);
void setup (){
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(ledR,HIGH); digitalWrite(ledA,LOW);digitalWrite(chapa,LOW);
  pinMode(A1,INPUT);
  lcd.begin(16,2); 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);     
  lcd.print("ENTER PASSWORD");
  lcd.setCursor(cursor,1);
  lcd.print("_a____");
  lcd.setCursor(cursor,1); 
}
void loop()
{
  pulsacion = teclado.getKey();
  if(pulsacion !=0)
  {
    if(pulsacion != '#' && pulsacion != '*' && clave ==0)
    {
  if(pulsacion != 1){
    lcd.print("*");
    cursor++;
    tone(buzzer,900);
    delay(200);
    noTone(buzzer);
  }
  if(pulsacion == codigoSecreto[posicion])
  posicion++;

  if(posicion == Clave)
  {
 lcd.setCursor(0,0);      
 lcd.print("WELCOME ESTEBAN");
 lcd.setCursor(0,1);
 lcd.print("  tiene 10 seg   "); 
 //tono del buzzer de bienvenida   
 tone(buzzer,1000); delay(200); noTone(buzzer); tone(buzzer,1200); delay(200); noTone(buzzer); tone(buzzer,1500); delay(200); noTone(buzzer);
 clave=1; //Significa que la Contraseña ha sido ingresada y correcta 
 digitalWrite(ledR,LOW); digitalWrite(ledA,HIGH); digitalWrite(chapa,HIGH);  
 delay(6000);
 clave=0;//Significa que despuès de 10 segundo la Clave estara vacia y debe que volver a ingresar para dar 1. 
 cursor=5;
 posicion=0;
 digitalWrite(ledA,LOW); digitalWrite(ledR,HIGH); digitalWrite(chapa,LOW); 
 lcd.init();
 lcd.setCursor(1,0);    
 lcd.print("ENTER PASSWORD");  
 lcd.setCursor(0,1); 
 lcd.print("     ______     ");
 lcd.setCursor(5,1);
 contador=0; //Contador serà 0 porque la contraseña es correcta. 
  }
if (cursor>10) {
  cursor=5;
  posicion=0; //lcd.setCursor(0,1); lcd.print("     ______     ");lcd.setCursor(5,1); //Si la clave ingresada no coincide entonces el contador incrementarà.     
  if(clave==0){ 
  tone(buzzer,70,500.900); delay(250); noTone(buzzer);
  contador++;
  lcd.init();
  lcd.setCursor(6,0);
  lcd.print("ACCESO"); 
  lcd.setCursor(5,1);
  lcd.print("DENEGADO");
  delay(3000);
  lcd.setCursor(1,0); 
  lcd.print("ENTER PASSWORD"); 
  lcd.setCursor(0,1); 
  lcd.print("     ______     ");            
  lcd.setCursor(5,1);
}      
 }
Serial.println(contador);
 //Si contador llega 3, entonces el contador se reiniciarà.
 if(contador==3){
   lcd.clear();
   for(int x=60; x>contador_tiempo; x--){
   delay(1000);
   tone(buzzer,1000,500);
   contador=0;
   if(x<10){ lcd.setCursor(10,1); lcd.print(" ");} //Si el contador de tiempo es menor a 10, en la pantalla se imprimirà spacio para que no se muestre el 0 del n10.
   lcd.setCursor(0,0);
   lcd.print("PUERTA BLOQUEADA");
   lcd.setCursor(0,1);
   lcd.print("TIEMPO R:");
   lcd.setCursor(9,1);
   lcd.print(x);
   }
   lcd.init();
   lcd.clear();
   lcd.setCursor(1,0);     // situamos el cursor el la posición 0 de la linea 0.
   lcd.print("ENTER PASSWORD"); // escribimos en LCD
   lcd.setCursor(0,1); //
   lcd.print("     ______     ");
   lcd.setCursor(5,1);
}  
 }
  }
////////////////CAMBIO DE CLAVE/////////////////////
 if(pulsacion == '#'){
  cambio_clave();
}////////////////////////////PULSADOR PARA PODER ABRIRLO DESDE DENTRO//////////////////////////////////////
if(digitalRead(A1) == HIGH){
   digitalWrite(ledR,LOW);digitalWrite(ledA,HIGH); digitalWrite(chapa,HIGH);
   lcd.init(); lcd.setCursor (5,0); lcd.print (" EXIT ");
   delay(10000);
   digitalWrite(ledR,HIGH);digitalWrite(ledA,LOW); digitalWrite(chapa,LOW);
   lcd.setCursor(0,0); lcd.print("ENTER PASSWORD"); lcd.setCursor(5,1); lcd.print("______"); lcd.setCursor(5,1);
 }
}
void cambio_clave(){
 lcd.clear(); lcd.init(); lcd.setCursor(1,0); lcd.print ("Menu de cambio");lcd.setCursor(5,1); lcd.print ("clave.");delay(1000); lcd.clear();lcd.init();
 lcd.clear();lcd.setCursor(0,0); lcd.print("Clave Antigua: "); lcd.setCursor(5,1); lcd.print("_a____"); lcd.setCursor(cursor,1);
 while(posicion<6){
      pulsacion = teclado.getKey(); 
      if(pulsacion !=0 && pulsacion !='#'){
      lcd.print("*");cursor++;
      if(cursor>11){
         error(); }
      tone(buzzer,900);delay(200); noTone(buzzer);
      if(pulsacion == codigoSecreto[posicion])
         posicion++; 
 } 
  }
 if(posicion == Clave){
    clave = 1; delay(400); posicion = 0; cursor=5; clave = 0;contador=0;clave_absoluta();}
 }
void error(){
  cursor=5; posicion=0; clave=0;
  tone(buzzer,70,500.900); delay(250); noTone(buzzer);
  lcd.clear(); lcd.init(); lcd.setCursor(6,0); lcd.print("ACCESO"); lcd.setCursor(5,1); lcd.print("DENEGADO"); delay(500);
  lcd.clear();lcd.setCursor(0,0); lcd.print("Clave Antigua: "); lcd.setCursor(5,1); lcd.print("_a____"); lcd.setCursor(cursor,1);
} 
void clave_absoluta(){
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("Clave 6 digitos:");
  while(posicion <6){
  pulsacion = teclado.getKey();
  if(pulsacion !=0){
  cursor<6; 
  lcd.setCursor(cursor,1);lcd.print("*");cursor ++;
  tone(buzzer,900); delay(200); noTone(buzzer);
  codigoSecreto[posicion]= pulsacion;
  posicion++;
}
 }
 clave = 0; posicion=0; cursor=5;
 lcd.clear(); lcd.init(); lcd.setCursor(1,0);lcd.print("CLAVE CAMBIADA");lcd.setCursor(4,1);lcd.print("CON EXITO"); 
 delay(2000);
 limpia();
}
 
 void limpia(){
  lcd.init();
  lcd.setCursor(1,0);    
  lcd.print("ENTER PASSWORD");  
  lcd.setCursor(0,1); 
  lcd.print("     ______     ");
  lcd.setCursor(5,1); 
 }
