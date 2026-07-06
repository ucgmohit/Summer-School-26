#include <SoftwareSerial.h>

SoftwareSerial BT(10,11);

const int RED = 2;
const int GREEN = 3;
const int BLUE = 4;

void setup() {

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  BT.begin(9600);
  Serial.begin(9600);

  Serial.println("Bluetooth LED Controller Ready");
}

void loop() {

  if(BT.available()){

    char cmd = BT.read();

    Serial.println(cmd);

    switch(cmd){

      case 'R':
        digitalWrite(RED,HIGH);
        digitalWrite(GREEN,LOW);
        digitalWrite(BLUE,LOW);
        break;

      case 'G':
        digitalWrite(RED,LOW);
        digitalWrite(GREEN,HIGH);
        digitalWrite(BLUE,LOW);
        break;

      case 'B':
        digitalWrite(RED,LOW);
        digitalWrite(GREEN,LOW);
        digitalWrite(BLUE,HIGH);
        break;

      case 'X':
        digitalWrite(RED,LOW);
        digitalWrite(GREEN,LOW);
        digitalWrite(BLUE,LOW);
        break;

      case 'F':

        for(int i=0;i<5;i++){

          digitalWrite(RED,HIGH);
          digitalWrite(GREEN,HIGH);
          digitalWrite(BLUE,HIGH);
          delay(300);

          digitalWrite(RED,LOW);
          digitalWrite(GREEN,LOW);
          digitalWrite(BLUE,LOW);
          delay(300);
        }

        break;
    }
  }

}
