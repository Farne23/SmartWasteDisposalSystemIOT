#ifndef __DOOR__
#define __DOOR__

#define OPEN_DEG 90
#define CLOSE_DEG 0
#define EMPTYING_DEG -90

#include "devices/actuators/ServoMotor.h"

class Door {
    public:
        virtual Door(ServoMotor* servo);
        virtual void open() = 0;
        virtual void close() = 0;
        virtual void empty() = 0;
    private:
        ServoMotor* servo;
};

#endif