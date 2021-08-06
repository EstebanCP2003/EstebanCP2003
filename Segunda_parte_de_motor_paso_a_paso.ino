int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int demora = 15;
int paso [4][4] =
{
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1},
 
};
void setup() {
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
}

void loop() {
 for (int x= 0; x < 512; x++) 
{
  for(int x = 0; x < 4; x++){
  digitalWrite(IN1, paso[x][0]);
  digitalWrite(IN2, paso[x][1]);
  digitalWrite(IN3, paso[x][2]);
  digitalWrite(IN4, paso[x][3]);
  delay(demora);
}
digitalWrite(IN1,LOW); //PASO1
 digitalWrite(IN2,LOW);
 digitalWrite(IN3,LOW);
 digitalWrite(IN4,LOW);
 delay(20);
}
}
