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
#include "ContainerGUIUpdate.h"
#include "devices/displays/DisplayImpl.h"

enum System_Status {
    NORMAL,
    PROBLEM_DETECTED,
    };

class Container : public ContainerTempDetection, public ContainerWasteDisposal, public ContainerGUIUpdate{
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
        double getFillPercentage();

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
        bool hasNormalBehaviour();

        void updateDashboard();
        void getDashboardInputs();
};

#endif