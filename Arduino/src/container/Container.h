#ifndef __CONTAINER__
#define __CONTAINER__

#include "devices/sensors/TempSensor.h"
#include "ContainerTempDetection.h"

class Container : public ContainerTempDetection{
    private:
        TempSensor* tempSensor;
    public:
        Container();
        void signalProblem();
        bool isFixed();
        double readTemperature();
};

#endif