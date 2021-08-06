#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27,16,2);

int buzzer = 13; //Alarma
int ahoras = 0; //Variable a mostrar por LCD de las horas
int aminutos = 0; //Variable a mostrar por LCD de los minutos
int asegundos = 0; //Variable a mostrar por LCD de los segundos
int segundostotal = 0; //Tiempo total
int msg= 0; //Barrera para el mensaje de bienvenida

int start = 3; //Pulsador de arranque
int empieza = 1024; // Variable para almacenaje del pulsador de arranque

int buth = 5; //Pulsador de Horas
int butm = 6; //Pulsador de Minutos
int buts = 9; //Pulsador de segundos

int varbuth = 0; //Variable para almacenar el valor del pulsador de horas
int varbutm = 0; //Variable para almacenar el valor del pulsador de minutos
int varbuts = 0; //Variable para almacenar el valor del pulsador de segundos

void setup()
{
lcd.init(); // Configuramos el numero de columnas y filas del LCD.

pinMode(buzzer, OUTPUT); //Pin de alarma –> Salida
pinMode(buth, INPUT); //Pin de pulsador de horas –> Entrada
pinMode(butm, INPUT); //Pin de pulsador de minutos –> Entrada
pinMode(buts, INPUT); //Pin de pulsador de segundos –> Entrada
pinMode(start, INPUT); //Pin de pulsador de arranque –> Entrada

msg = 0; //Barrera del mensaje de bienvenida
empieza = 1024; //Barrera de arranque

varbuth = 1; //Barrera de horas
varbutm = 1; //Barrera de minutos
varbuts = 1; //Barrera de segundos
lcd.backlight();
}

void loop(){
  
if(msg==0) //Mostramos el mensaje de bienvenida solo una vez
{
lcd.setCursor(0,0);
lcd.print("Temporizador com");
lcd.setCursor(1,1);
lcd.print("Arduino + LCD");
delay(2500);
msg = 1;
lcd.clear();
}

//————————————————————————————————-
// LECTURA DE LOS BOTONES Y ELECCIÓN DEL TIEMPO, NO SALE DEL BUCLE HASTA PULSAR
// EL BOTON DE ARRANQUE
//————————————————————————————————-


varbuth = analogRead(buth); //Leemos boton de horas
varbutm = analogRead(butm); //Leemos boton de minutos
varbuts = analogRead(buts); //Leemos boton de segundos

if(varbuth == 0) //Si el boton ha sido pulsado, aumentamos las horas en una unidad
{
ahoras = ahoras + 1 ;
delay(250);
}

if(varbutm == 0) //Si el boton ha sido pulsado, aumentamos los minutos en una unidad
{
aminutos = aminutos + 1;
delay(250);
}

if(varbuts == 0) //Si el boton ha sido pulsado, aumentamos los segundos en una unidad
{
asegundos = asegundos + 1;
delay(250);
}

lcd.setCursor(0,0);
lcd.print("Digite o Tempo"); //Muestra mensaje y las HH:MM:SS que vayamos aumentando

lcd.setCursor(4,1);

if (ahoras < 10) 
{
lcd.print('0'); // Si las horas son menor que 10, pone un "0" delante.

lcd.print(ahoras); // Sin este codigo, se muestra asi: H:M:S (1:M:S)
lcd.print(":");
}

if (aminutos < 10) 
{
lcd.print('0');// Si los minutos son menor que 10, pone un "0" delante.
lcd.print(aminutos); // Sin este codigo, se muestra asi: H:M:S (H:1:S)

lcd.print(":");
}
if (asegundos < 0)
{
delay (1000); //Descontamos en periodos de 1 segundo
segundostotal= segundostotal -1;

ahoras = ((segundostotal / 60)/ 60); //Convertimos los segundos totales en horas
aminutos = (segundostotal / 60 % 60); //Convertimos los segundos totales en minutos
asegundos = (segundostotal % 60); //Convertimos los segundos totales en periodos de 60 segundos

lcd.setCursor(0,0);
lcd.print("Tiempo restante"); //Mostramos mensaje de tiempo restante

lcd.setCursor(4,1);
}
if (ahoras < 10) 
{
lcd.print('0'); // Si las horas son menor que 10, pone un "0" delante.
lcd.print(ahoras); // Sin este codigo, se muestra asi: H:M:S (1:M:S)
lcd.print(":");
}

if (aminutos < 10)
{
lcd.print('0'); // Si los minutos son menor que 10, pone un "0" delante.
lcd.print(aminutos); // Sin este codigo, se muestra asi: H:M:S (H:1:S)


lcd.print(":");
}
if (asegundos < 10)
{ 
lcd.print('0');// si el valor de segundo esta por debajo de 9 (unidad) antepone un cero
lcd.print(asegundos); // Sin este codigo, se muestra asi: H:M:S (H:M:1)
}
if (segundostotal == 0) //Si finaliza el tiempo
{

}
 while(1) //Bucle infinito mostrando mensaje y haciendo parpadear un led
{
lcd.clear();
lcd.setCursor(5,0);
lcd.print("Tiempo");
lcd.setCursor(3,1);
lcd.print("Finalizado");
digitalWrite(buzzer, HIGH);
delay(200);
digitalWrite(buzzer, LOW);
delay(200);

}

}
 
