#ifndef __CONTAINER__
#define __CONTAINER__

#include "devices/sensors/TempSensor.h"
#include "devices/lights/LightSignals.h"
#include "devices/detectors/Detector.h"
#include "devices/detectors/UserDetector.h"
#include "devices/lights/Led.h"
#include "devices/displays/Display.h"
#include "devices/buttons/ButtonPanel.h"
#include "devices/actuators/Door.h"
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
        Sensor* sonar;
        LightSignals* lightSignals;
        Detector* userDetector;
        Display* display;
        ButtonPanel* buttonPanel;
        Door* door;
        double fillPercentage();

    public:
        Container();
        void signalProblem();
        bool isFixed();
        double readTemperature();

        bool userDetected();
        void signalAvailability();
        void goToSleep();
        void spill();
        void stopAccepting();
        bool openRequested();
        bool closeRequested();
        bool isFull();
        void receiveWaste();
        bool emptyRequested();
        void empty();
};

#endif