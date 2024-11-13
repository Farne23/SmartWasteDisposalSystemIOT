#ifndef __USER_DETECTOR__
#define __USER_DETECTOR__

#include "Detector.h"

class UserDetector: public Detector {
    public:
        UserDetector(int pin);
        bool detect();
    private:
        int pin;
};

#endif