#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27,16,2);

int contador1 =0;
int contador2 = 0;
int LED1 = 13;
int Buzzer = 8;
int botton = 2;
int botton1 = 3;

// Creamos un caracter, en este caso creè una flecha

byte flecha [8] = {

  B00000,
  B00100,
  B00110,
  B11111,
  B11111,
  B00110,
  B00100,
  B00000,
};
void setup() {
  Serial.begin(9600);
  pinMode(LED1,OUTPUT);
  pinMode(Buzzer,OUTPUT);
  pinMode(botton,INPUT);
  pinMode(botton1,INPUT);
  lcd.init();   // inicializamos la pantalla lcd
  lcd.backlight(); // le damos luz a la pantalla
  lcd.setCursor(0,0);   //Menu de bienvenida
  lcd.print("Menu de ensayo");
  lcd.setCursor(5,1);
  lcd.print("2021");
  delay(4000);
  lcd.clear();// Aqui termina el intro de bienvenida
  lcd.write(byte(0));  
  lcd.createChar(0,flecha);
  lcd.setCursor(1,0);
  lcd.print("LED AZUL:");
  lcd.setCursor(10,0);
  lcd.print("OFF");
  lcd.setCursor(1,1);
  lcd.print("BUZZER:OFF");
} 
void loop() {
 
  
  // Ponemos a evaluar si el botton ha sido pulsado 
  if(digitalRead(2) == 1){
    delay(100);
    if(digitalRead(2) == 0){
      contador1 = contador1 +1;
}
  }
  if(contador1 == 1){     // Si el botton fue pulsado el contador aumenta y imprimira esto en la pantalla lcd
    lcd.setCursor(0,0);
    lcd.write(byte(0));
    lcd.setCursor(0,1);
    lcd.print(" ");
    
  }
  if(contador1 == 2){  // Si el botton ha sido nuevamente pulsado se imprimirà esto en la lcd
    lcd.setCursor(0,0);
    lcd.print(" ");
    lcd.setCursor(0,1);
    lcd.write(byte(0));
    lcd.setCursor(1,1);
    lcd.print("BUZZER:OFF");
}
  if(contador1 >=2){ //Aqui decimos si el contador es mayor o igual a 2 entonces iniciamos el contador1 para que se ejucute de nuevo 
    contador1 = 0;  // lo de arriba
  }
 // Ponemos a evaluar si el botton ha sido pulsado 
 if(digitalRead(3) == 1 ){
    delay(100);
    if(digitalRead(3) == 0){
      contador2 = contador2 +1;
}
  }
  
  
 if(contador2 == 1){
  Serial.print(contador2);
  lcd.setCursor(10,0);
  lcd.print("ON");
  digitalWrite(LED1, HIGH);
 lcd.setCursor(12,0);
  lcd.print(" ");
  }
 if(contador2 == 2){
   lcd.setCursor(10,0);
  lcd.print("OFF");
  digitalWrite(LED1, LOW);
   
 } 
 if(contador2 == 3){
    digitalWrite(Buzzer,HIGH);
    lcd.setCursor(8,1);
    lcd.print("ON");
    lcd.setCursor(10,1);
    lcd.print(" ");
   
 }
  if(contador2 == 4){
   digitalWrite(Buzzer,LOW);
    lcd.setCursor(1,1);
    lcd.print("BUZZER:OFF");
 }
 
 if(contador2 >=4){ //Aqui decimos si el contador es mayor o igual a 2 entonces iniciamos el contador1 para que se ejucute de nuevo 
    contador2 = 0;  // lo de arriba
 }
}
