#ifndef __CONTAINER__
#define __CONTAINER__

#include "devices/sensors/TempSensor.h"
#include "devices/lights/LightSignals.h"
#include "devices/detectors/Detector.h"
#include "devices/detectors/UserDetector.h"
#include "devices/lights/Led.h"
#include "ContainerTempDetection.h"
#include "ContainerWasteDisposal.h"

enum System_Status {
    NORMAL,
    PROBLEM_DETECTED,
    };

class Container : public ContainerTempDetection, public ContainerWasteDisposal{
    private:
        System_Status status;
        TempSensor* tempSensor;
        LightSignals* lightSignals;
        Detector* userDetector;
        Display* display;
        ButtonPanel* buttonPanel;
        Door* door;

    public:
        Container();
        void signalProblem();
        bool isFixed();
        double readTemperature();

        bool userDetected();
        void signalAvailability();
        void goToSleep();
        void spill();
        bool openRequested();
        bool closeRequested();
};

#endif