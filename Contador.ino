int contador = 0; 
int botton = 2;
int LED = 13;
void setup() {
  Serial.begin(9600);
  pinMode(botton,INPUT);
  pinMode(LED,OUTPUT);
}

void loop() {
if(digitalRead(2) == 1 ){
   // Forma de declarar la instrucción delay
    // delay (Cantidad de tiempo a esperar en MILISEGUNDOS)
    delay(100);
    if(digitalRead(2) == 0){
      contador = contador +1;
      Serial.println(contador);
    }
}
if(contador == 20){
    digitalWrite(LED,HIGH);
  }
  if (contador == 40){
    digitalWrite(LED,LOW);
  }
  if (contador >=40){
    contador =0;
  }
}
