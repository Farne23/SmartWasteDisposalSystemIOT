#include "devices/actuators/Door.h"

//DELETEME
#include <Arduino.h>

Door::Door(ServoMotor* servo){
    this->servo = servo;
    this->servo->on();
    this->close();
}

void Door:: open(){
    //DELETE ME
    Serial.println("DEVO APRIRE");
    this->servo->setPosition(OPEN_DEG);
}

void Door::close(){
    this->servo->setPosition(CLOSE_DEG);
}

void Door::empty(){
    this->servo->setPosition(EMPTYING_DEG);
}

