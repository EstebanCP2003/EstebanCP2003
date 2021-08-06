int buzzer = 11;
int Pulsador_do = 2;
int Pulsador_re = 3;
int Pulsador_mi = 4;
int Pulsador_fa = 5;
int Pulsador_sol = 6;
int Pulsador_la = 7;
int Pulsador_si = 8;

void setup() {
  Serial.begin(9600);
 pinMode(buzzer,OUTPUT);
 pinMode(Pulsador_do,INPUT);
 pinMode(Pulsador_re,INPUT);
 pinMode(Pulsador_mi,INPUT);
 pinMode(Pulsador_fa,INPUT);
 pinMode(Pulsador_sol,INPUT);
 pinMode(Pulsador_la,INPUT);
 pinMode(Pulsador_si,INPUT);
}

void loop() {
  if(digitalRead(2) == 1){
  tone(11,220,500);
  }
if(digitalRead(3) == 1){
  tone(11,248,500);
  }
  if(digitalRead(4) == 1){
  tone(11,262,500);
  }
  if(digitalRead(5) == 1){
  tone(11,296,500);
  }
  if(digitalRead(6) == 1){
  tone(11,315,500);
  }
  if(digitalRead(7) == 1){
  tone(11,420,500);
  }
  if(digitalRead(8) == 1){
  tone(11,520,500);
  }
}
