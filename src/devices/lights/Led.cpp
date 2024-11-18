#include "Led.h"
#include "Arduino.h"

/*Basic implementation of a class rappresenting a Led 
wich can be managed through a specified pin*/

Led::Led(int pin){
  this->pin = pin;
  pinMode(pin,OUTPUT);
}

void Led::switchOn(){
  digitalWrite(pin,HIGH);
}

void Led::switchOff(){
  digitalWrite(pin,LOW);
};
