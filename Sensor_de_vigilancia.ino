int pir = 2;
int led1 = 3;
int led2 = 4;
int buzzer = 5;

void setup() {
  pinMode (2, INPUT);
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  Serial.begin (9600);
}

void loop(){
 if(digitalRead(2) == HIGH)
{
 digitalWrite(3, HIGH); 
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  Serial.println("!INTRUSO¡");
 }
   else 
   {
   digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  Serial.println("MODO VIGILANTE");
    
   }
}
