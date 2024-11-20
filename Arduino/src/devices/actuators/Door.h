#ifndef __DOOR__
#define __DOOR__

class Door {
    public:
        virtual void open() = 0;
        virtual void close() = 0;
        virtual void emptying() = 0;
};

#endif