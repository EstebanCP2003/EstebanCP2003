#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);



byte b[8] = {
  B01110,
  B01110,
  B00100,        //NIÑO
  B01110,
  B10101,
  B00100,
  B01010,
  B01010,
};

byte c[8] = {
  B11111,
  B01110,
  B00100,
  B01110,       //NIÑA
  B10101,
  B00100,
  B01010,
  B01010,
};
byte d[8] = {
  B00000,
  B10101,
  B11111,       //FLOR
  B11111,
  B01110,
  B00100,
  B00100,
  B00100,
  
};
byte a[8] = {
B00000,
B01010,
B11111,            //corazon
B11111,
B11111,
B01110,
B00100,
B00000,

};

void setup(){
 lcd.init();
 lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("FELIZ DIA DE LA");
  lcd.setCursor(5,1);
  lcd.write(byte(0));
  lcd.setCursor(6,1);
  lcd.print("MUJER");
  lcd.setCursor(11,1);
  lcd.write(byte(0));
  delay(5000);
  lcd.clear();
 lcd.createChar(0,a);
 lcd.createChar(1,b);
 lcd.createChar(2,c);
 lcd.createChar(3,d);
 lcd.begin(16,2);

}
 
void loop(){
  lcd.setCursor(1,0);
  lcd.print("TE AMO MUCHO");
  lcd.setCursor(13, 0);
  lcd.write(byte(0));
  
  lcd.setCursor(6, 1);
  lcd.write(byte(1));

  lcd.setCursor(7,1);
  lcd.write(byte(3));

  lcd.setCursor(8,1);
  lcd.write(byte(2));

}
