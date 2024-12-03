#ifndef __CONTAINER__
#define __CONTAINER__

#include "devices/sensors/TempSensor.h"
#include "devices/lights/LightSignals.h"
#include "devices/detectors/Detector.h"
#include "devices/detectors/UserDetector.h"
#include "devices/lights/Led.h"
#include "devices/displays/Display.h"
#include "devices/buttons/ButtonPanel.h"
#include "devices/buttons/ButtonImpl.h"
#include "devices/sensors/Sonar.h"
#include "dashboard/Dashboard.h"
#include "devices/actuators/Door.h"
#include "devices/actuators/ServoMotorImpl.h"
#include "ContainerTempDetection.h"
#include "ContainerWasteDisposal.h"
#include "ContainerSleepModeManager.h"
#include "ContainerGUIUpdate.h"
#include "devices/displays/DisplayImpl.h"

enum System_Status {
    NORMAL,
    PROBLEM_DETECTED,
    };

class Container : public ContainerTempDetection, public ContainerWasteDisposal, public ContainerGUIUpdate, public ContainerSleepModeManager{
    private:
        System_Status status;
        Sensor* tempSensor;
        Sensor* sonar;
        LightSignals* lightSignals;
        Detector* userDetector;
        Display* display;
        ButtonPanel* buttonPanel;
        Door* door;
        Dashboard* dashboard;
        double fillPercentage;
        double fillLevel;
        double temperature;
        bool sleeping;
        bool emptyNeeded;
        double getFillPercentage();

    public:
        Container();
        void signalProblem();
        bool isFixed();
        double readTemperature();

        void spill();
        void signalAvailability();
        bool openRequested();
        bool closeRequested();
        bool isFull();
        void receiveWaste();
        void stopAccepting();
        bool emptyRequested();
        void empty();
        bool hasNormalBehaviour();

        void updateDashboard();
        void getDashboardInputs();
        bool isEmptyNeeded();

        void goToSleep();
        void wakeUp();
        bool userDetected();

        bool isSleeping();
};

#endif