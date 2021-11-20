#include "Arduino.h"
#include "Motor.h"


Motor::Motor(int plus, int minus, int enc_a, int enc_b) {
  pinMode(plus,OUTPUT);
  pinMode(minus,OUTPUT);
  pinMode(enc_a,INPUT_PULLUP);
  pinMode(enc_b,INPUT_PULLUP);
  Motor::plus = plus;
  Motor::minus = minus;
  Motor::enc_a = enc_a;
  Motor::enc_b = enc_b;
}

void Motor::rotate(int value) {
  if(value>=0){
    //Max Voltage with 16V battery with 12V required
    //(12/16)*255 ~=190
//    Serial.println("called");
//    Serial.println(plus);
    int out = map(value, 0, 100, 0, 190);
    analogWrite(plus,out);
    analogWrite(minus,0);
  }else{
    //Max Voltage with 16V battery with 12V required
    //(12/16)*255 ~=190
    int out = map(value, 0, -100, 0, 190);
    analogWrite(plus,0);
    analogWrite(minus,out);
  }
}
