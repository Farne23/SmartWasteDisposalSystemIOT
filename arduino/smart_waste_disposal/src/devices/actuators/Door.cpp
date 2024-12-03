#include "devices/actuators/Door.h"

Door::Door(ServoMotor* servo){
    this->servo = servo;
    this->servo->on();
    this->close();
}

void Door:: open(){
    this->servo->setPosition(OPEN_DEG);
}

void Door::close(){
    this->servo->setPosition(CLOSE_DEG);
}

void Door::empty(){
    this->servo->setPosition(EMPTYING_DEG);
}

