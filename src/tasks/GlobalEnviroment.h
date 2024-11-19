#ifndef __GLOBALENVIROMENT__
#define __GLOBALENVIROMENT__

#include "devices/lights/LightSignals.h"
/* 
A class realized to manage access to the variable, 
shared between the two tasks, wich keeps track of the global status of the system.
It allows to switch between the problem detected phase, wich disables the regual waste 
disposal system flow, and the normal phase, where the system works regurlary. 
*/

class GlobalEnviroment{
    private:
    System_Status status;
    LightSignals lightSignals;
    public:
    virtual bool problemDetected();
    virtual void signalProblem();
    virtual void signalNormal();
};

enum System_Status {
    NORMAL,
    PROBLEM_DETECTED,
    };

#endif