#ifndef __DOOR__
#define __DOOR__

#define OPEN_DEG 90
#define CLOSE_DEG 0
#define EMPTYING_DEG -90

#include "devices/actuators/ServoMotor.h"

class Door {
    public:
        Door(ServoMotor* servo);
        void open();
        void close();
        void empty();
    private:
        ServoMotor* servo;
};

#endif