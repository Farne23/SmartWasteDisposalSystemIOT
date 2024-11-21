#ifndef __CONTAINER__
#define __CONTAINER__

#include "devices/sensors/TempSensor.h"
#include "devices/light/LightSignals.h"
#include "devices/light/Led.h"
#include "ContainerTempDetection.h"

enum System_Status {
    NORMAL,
    PROBLEM_DETECTED,
    };

class Container : public ContainerTempDetection{
    private:
        System_Status status;
        TempSensor* tempSensor;
        LightSignals* lightSignals;
    public:
        Container();
        void signalProblem();
        bool isFixed();
        double readTemperature();
};

#endif