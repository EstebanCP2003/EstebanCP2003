#include <IRremote.h>      // importa libreria IRremote
#define Boton_1 0xF30CFF00  // reemplaza cada instancia de Boton_1 por su valor HEX
#define Boton_2 0xE718FF00   // reemplaza cada instancia de Boton_2 por su valor HEX
#define Boton_3 0xA15EFF00 // reemplaza cada instancia de Boton_3 por su valor HEX
#define Boton_4 0xF708FF00
#define Boton_5 0xE31CFF00
#define Boton_6 0xA55AFF00


int SENSOR = 11;      // sensor KY-022 a pin digital 11

int LEDROJO = 2;      // componente rojo de LED RGB a pin 2
int LEDVERDE = 3;     // componente verde de LED RGB a pin 3
int LEDAZUL = 4;      // componente azul de LED RGB a pin 4
int LEDBLANCO =5;
int LEDAMARILLO =6;


void setup() {
  Serial.begin(9600);     // inicializa comunicacion serie a 9600 bps
  IrReceiver.begin(SENSOR, DISABLE_LED_FEEDBACK); // inicializa recepcion de datos
  pinMode(LEDROJO, OUTPUT);   // pin 2 como salida
  pinMode(LEDVERDE, OUTPUT);    // pin 3 como salida
  pinMode(LEDAZUL, OUTPUT);   // pin 4 como salida
  pinMode(LEDBLANCO, OUTPUT);
  pinMode(LEDAMARILLO, OUTPUT);
 
  
} 

void loop() {
  if (IrReceiver.decode()) {        // si existen datos ya decodificados
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // imprime valor en hexadecimal en monitor
    if (IrReceiver.decodedIRData.decodedRawData == Boton_1)   // si codigo recibido es igual a Boton_1
    digitalWrite(LEDROJO, !digitalRead(LEDROJO)); // enciende o apaga componente rojo

    if (IrReceiver.decodedIRData.decodedRawData == Boton_2)   // si codigo recibido es igual a Boton_2
    digitalWrite(LEDVERDE, !digitalRead(LEDVERDE)); // enciende o apaga componente verde

    if (IrReceiver.decodedIRData.decodedRawData == Boton_3)   // si codigo recibido es igual a Boton_3
    digitalWrite(LEDAZUL, !digitalRead(LEDAZUL)); // enciende o apaga componente azul

     if (IrReceiver.decodedIRData.decodedRawData == Boton_4)   // si codigo recibido es igual a Boton_3
    digitalWrite(LEDBLANCO, !digitalRead(LEDBLANCO)); 

     if (IrReceiver.decodedIRData.decodedRawData == Boton_5)   // si codigo recibido es igual a Boton_3
    digitalWrite(LEDAMARILLO, !digitalRead(LEDAMARILLO)); 

     if(IrReceiver.decodedIRData.decodedRawData == Boton_6)
      for(int x=2;x<7;x++)
    {
      digitalWrite(x, HIGH);
      delay(200);
      digitalWrite(x,LOW);
      delay(200);
    }
    
    IrReceiver.resume();        // resume la adquisicion de datos
  }
 
  delay (100);            // breve demora de 100 ms.
}
