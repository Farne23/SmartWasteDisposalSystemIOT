#ifndef __TASK__
#define __TASK__

#include "GlobalEnviroment.h"

/**
 * Abastract class rappresenting an interface for a generic task of FSM.
 */
class Task {
    int myPeriod;
    int timeElapsed;
    GlobalEnviroment* enviromentStatus;

    public:
    virtual void init(int period, GlobalEnviroment* enviromentStatus){
        myPeriod = period;  
        timeElapsed = 0;
        this->enviromentStatus = enviromentStatus;
    }

    /* Handler for the tick of the FSM*/
    virtual void tick() = 0;

    bool updateAndCheckTime(int basePeriod){
        timeElapsed += basePeriod;
        if (timeElapsed >= myPeriod){
            timeElapsed = 0;
            return true;
        } else {
            return false; 
        }
    }
  
};

#endif