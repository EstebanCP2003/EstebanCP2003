#include <Servo.h>

Servo myservo;
Servo servo;

const int buttonPin = 2;
int val;
int buttonState = 0;

void setup()
{
  servo.attach (4);
  myservo.attach(9);
  pinMode(buttonPin, INPUT);       
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {     
    val = 160; 
  }
  else {
    val = 0;
  }
  servo.write(val);
  myservo.write(val);
  delay(15);
}
