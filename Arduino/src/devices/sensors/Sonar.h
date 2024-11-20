#ifndef __SONAR__
#define __SONAR__

#include "Sensor.h" 

class Sonar: public Sensor {
    public:
        Sonar(int trig, int echo);
        double sense();
    private:
        int trig, echo;
};

#endif