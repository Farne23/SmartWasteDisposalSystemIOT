#ifndef __TASK__
#define __TASK__

#include "GlobalEnviroment.h"

/**
 * Abastract class rappresenting an interface for a generic task of FSM.
 */
class Task {
    int myPeriod;
    int timeElapsed;

    public:
    virtual void init(int period){
        myPeriod = period;  
        timeElapsed = 0;
    }

    /* Handler for the tick of the FSM*/
    virtual void tick() = 0;
    /* Function used to set up the Task to the wantend inital conditions*/
    virtual void initBehaviour();

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