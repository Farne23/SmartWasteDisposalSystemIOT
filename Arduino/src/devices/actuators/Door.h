#ifndef __DOOR__
#define __DOOR__

class Door {
    public:
        virtual void Door(ServoMotor* Servo)=0;
        virtual void open() = 0;
        virtual void close() = 0;
        virtual void empty() = 0;
};

#endif