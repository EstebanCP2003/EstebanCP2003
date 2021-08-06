int Led_BCL = 10;//bateria casi llena 

void setup(){
Serial.begin(9600);
pinMode(Led_BCL, OUTPUT);

}
void loop(){

int SensorvalueB= analogRead(A0);
float Voltaje = SensorvalueB* (5.00/1023)*2.7;
  
  Serial.print("Voltaje de entrada A0 =");
  Serial.print(Voltaje);
  Serial.println();
  delay(1000);
  
  if(Voltaje<9){
   digitalWrite(Led_BCL, HIGH);
  }
  else{
   digitalWrite(Led_BCL, LOW);
  }
}
