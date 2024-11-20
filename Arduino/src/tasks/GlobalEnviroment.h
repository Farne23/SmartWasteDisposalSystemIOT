#ifndef __GLOBALENVIROMENT__
#define __GLOBALENVIROMENT__

#include "devices/lights/LightSignals.h"
#include "pins/HwInterfaces.h"
/* 
A class realized to manage access to the variable, 
shared between the two tasks, wich keeps track of the global status of the system.
It allows to switch between the problem detected phase, wich disables the regual waste 
disposal system flow, and the normal phase, where the system works regurlary. 
*/
enum System_Status {
    NORMAL,
    PROBLEM_DETECTED,
    };

class GlobalEnviroment{
    private:
    System_Status status;
    LightSignals* lightSignals;
    void init();
    public:
    GlobalEnviroment();
    bool problemDetected();
    void signalProblem();
    void signalNormal();
    /**
     * FUNZIONI SPECIFICHE PER LE LUCI, DA VALUTARE SE OPERAZIONI DA LASICARE SEPARATE O SE POSSIBILE INCLUDERE IN ALTRE FUNZIONI.
     */
    void signalAvailability_lights();
    void signalSleep_lights();   
    void signalProblem_lights(); 
};

#endif