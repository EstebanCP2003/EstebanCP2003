#include <IRremote.h>    // importa libreria IRremote

int SENSOR = 11;        // sensor KY-022 a pin digital 11  
 IRrecv irrecv (SENSOR);
 decode_results codigo;
void setup() { 
  Serial.begin(9600);             // inicializa comunicacion serie a 9600 bps
  IrReceiver.begin(SENSOR, DISABLE_LED_FEEDBACK);     // inicializa recepcion de datos
} 

void loop() { 
  if (IrReceiver.decode()) {          // si existen datos ya decodificados
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // imprime valor en hexadecimal en monitor
    IrReceiver.resume();              // resume la adquisicion de datos
  }
  delay (100);                  // breve demora de 100 ms.
}
