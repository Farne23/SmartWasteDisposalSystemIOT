#ifndef __TASK__
#define __TASK__

#include "GlobalEnviroment.h"

/**
 * Abastract class rappresenting an interface for a generic task of FSM.
 */
class Task {
    int myPeriod;
    int timeElapsed;
    GlobalEnviroment* globalEnviroment;

    public:
    virtual void init(int period, GlobalEnviroment* globalEnviroment){
        myPeriod = period;  
        timeElapsed = 0;
        this->globalEnviroment = globalEnviroment;
        this->initComponents();
    }

    /* Handler for the tick of the FSM*/
    virtual void tick() = 0;
    /* Function used to set up the Task to the wantend initali conditions*/
    virtual void initComponents();

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