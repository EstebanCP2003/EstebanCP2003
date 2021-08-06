int SHM1= 10;
int SHM2= 11;
int SAM1= 3;
int SAM2= 2;


void setup()
{
  pinMode(SHM1, OUTPUT);
  pinMode(SHM2, OUTPUT);
  pinMode(SAM1, OUTPUT);
  pinMode(SAM2, OUTPUT);
}

void loop()
{
  digitalWrite(SHM1, HIGH);
  digitalWrite(SHM2, HIGH);
  digitalWrite(SAM1, LOW);
  digitalWrite(SAM2, LOW);
  delay(3000);
  
  digitalWrite(SHM1, LOW);
  digitalWrite(SHM2, LOW);
  digitalWrite(SAM1,HIGH);
  digitalWrite(SAM2,HIGH);
  delay(3000);
}
