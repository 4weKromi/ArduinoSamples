#include <Keypad.h>
#include <Servo.h>

//servo pin D11
//keypad pin D2-D9

Servo myServo;
const byte R = 4; //rows
const byte C = 4; //columns
char keys[R][C] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
//signal pin is 11
byte rPins[R] = {9, 8, 7, 6};
byte cPins[C] = {5, 4, 3, 2};
int _sPin = 11;
int sAngle=90;

int lBound=22, uBound=180;

Keypad kp = Keypad( makeKeymap(keys), rPins, cPins, R, C);

void setup() {
  Serial.begin(9600);
  myServo.attach(_sPin);
}

void loop() {
  char cKey;
  if((cKey=kp.getKey())!=NULL){
    Serial.println(cKey);
  } 
  if(cKey=='B'&&sAngle<=uBound){
    sAngle+=5;
    myServo.write(sAngle);
  }
  if(cKey=='A'&&sAngle<=uBound){
    sAngle+=20;
    myServo.write(sAngle);
  }
  if(cKey=='C'&&sAngle>=lBound){
    sAngle-=5;
    myServo.write(sAngle);
  }
  if(cKey=='D'&&sAngle>=lBound){
    sAngle-=20;
    myServo.write(sAngle);
  }
}
