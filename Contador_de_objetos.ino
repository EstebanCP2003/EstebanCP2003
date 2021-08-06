#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27,16,2);

const int irojo1 = A1;
int evento1;
int contador1 = 0;

void setup() {
 pinMode(irojo1,INPUT);
 lcd.init();
 lcd.backlight();
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("PROYECT:");
 lcd.setCursor(0,1);
 lcd.print("OBJECTS COUNTER");
 delay(5000);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Entrada:");
 lcd.setCursor(8,0);
 lcd.print('0');
 delay(1000);
 Serial.begin(9600);

}

void loop() {
 delay(200);
 evento1=analogRead(irojo1);
 Serial.println("Evento1");
 Serial.println(evento1);
 
 if(evento1 !=580){
  lcd.setCursor(0,1);
  lcd.print("            ");
 }
 if(evento1<580){
  contador1++;
  lcd.setCursor(8,0);
  lcd.print(contador1);
  delay(500);
 }
  else{
  lcd.setCursor(0,1);
  lcd.print("Esperando...");
 }
}
