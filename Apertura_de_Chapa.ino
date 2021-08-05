#include <Servo.h>
#include <Keypad.h>

const byte filas = 3, columnas = 3;
char teclado_digital [filas][columnas]= {
    {'1','2','3'},
    {'4','5','6'},  
    {'7','8','9'},
  };

const byte pin_filas[filas] = {10,9,8,};
const byte pin_columnas[columnas] = {7,6,5};

Keypad keypad = Keypad(makeKeymap(teclado_digital), pin_filas, pin_columnas, filas, columnas);
Servo chapa;

char password[5];
int posicion = 0;

void setup() {
  Serial.begin(9600);
  chapa.attach(13);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  while(posicion<5){
    char tecla = keypad.getKey(); 
    password[posicion] = tecla ;
    if(tecla){
      Serial.print("*");
      posicion ++;
    }
  } 

  Serial.println("");
  if(password[0] == '4'&& password[1] == '5'&& password[2] == '7'
  && password[3] == '6'&& password[4] == '9'){
    Serial.println("Clave correcta, acceso autorizado.");
    digitalWrite(4,1);
    chapa.write(0);
    delay(20000);
  }  else{
       Serial.println("Clave incorrecta, acceso denegado.");
       digitalWrite(3,1);
       digitalWrite(11,1);
       delay(5000);
     }
  posicion = 0;
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(11,0);
  chapa.write(90);
}
