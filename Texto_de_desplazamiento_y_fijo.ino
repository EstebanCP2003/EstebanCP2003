#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int screenwidth = 16;
int screenMeight = 16;
String line1 = "LA VIDA ES BELLA";
String line2 = "PERO MAS BELLA LAS MUJERES HERMOSAS QUE ESTAN LEYENDO ESTO";
int stringStart, stringStop = 0;
int scrollCursor = screenwidth;



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


void setup() {
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
 lcd.begin(16,2);
  
}

void loop() {

  lcd.setCursor(0,0);
  lcd.print(line1);

 lcd.setCursor(scrollCursor, 1);
 lcd.print(line2.substring(stringStart,stringStop));
 
 delay(200);
 lcd.clear();

 if(stringStart == 0 && scrollCursor > 0) {
  stringStop++;
  scrollCursor--;
 }
 else if (stringStart == stringStop){
  stringStart = stringStop = 0;
  scrollCursor = screenwidth;
 }
 else if (stringStop == line2.length()&& scrollCursor == 0){
  stringStart++;
 }
 else{
  stringStart++;
  stringStop++;
 }
}
