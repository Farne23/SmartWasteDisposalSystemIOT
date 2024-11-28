#ifndef __DOOR__
#define __DOOR__

#define OPEN_DEG 180
#define CLOSE_DEG 90
#define EMPTYING_DEG 0

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