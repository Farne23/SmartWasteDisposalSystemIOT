#include "Container.h"
#include "settings/HwInterfaces.h"

#define CONTAINER_FULL_DISTANCE 0.15 //threshold rappresenting the distance  the sonar has to sense in order to consider the container full
#define CONTAINER_EMPTY_DISTANCE 0.25

Container::Container(){
    this->tempSensor = new TempSensor(TEMP_SENSOR_PIN);
    this->sonar = new Sonar(SONAR_TRIG,SONAR_ECHO);
    this->lightSignals = new LightSignals(new Led(GREEN_LED_PIN), new Led(RED_LED_PIN));
    this->userDetector = new UserDetector(USER_DETECTOR_PIN);
    this->display = new DisplayImpl();
    this->buttonPanel = new ButtonPanel(new ButtonImpl(OPEN_BUTTON_PIN),new ButtonImpl(CLOSE_BUTTON_PIN));
    this->door = new Door(new ServoMotorImpl(SERVO_MOTOR_PIN));
    this->dashboard = new Dashboard();
    this->status=NORMAL;
}

double Container::readTemperature(){
    this->temperature = this->tempSensor->sense();
    return this->temperature;
}

void Container::signalProblem(){
    this->status=PROBLEM_DETECTED;
    this->lightSignals->signalProblem();
}

bool Container::isFixed(){
    if(this->dashboard->getRepair()){
        this->status=NORMAL;
    }
    return this->status==NORMAL;
}

bool Container::userDetected(){
    return this->userDetector->detect();
}

bool Container::isSleeping(){
    return sleeping;
}


void Container::signalAvailability(){
    //this->door->close();
    this->lightSignals->signalAvailability();
    this->display->displayReadyToOpen();
}

void Container::goToSleep(){
    this->sleeping = true;
    this->lightSignals->signalSleep();
}

void Container::wakeUp(){
    this->sleeping = false;
}

bool Container::openRequested(){
    return this->buttonPanel->openRequested();
}

bool Container::closeRequested(){
    return this->buttonPanel->closeRequested();
}

void Container::spill(){
    this->display->displayReadyToClose();
    this->door->open();
}

bool Container::isFull(){
    return (this->getFillPercentage())>=100;
}

double Container::getFillPercentage(){
    this->fillPercentage = ((this->sonar->sense()-CONTAINER_EMPTY_DISTANCE)/(CONTAINER_FULL_DISTANCE-CONTAINER_EMPTY_DISTANCE))*100;
    return this->fillPercentage ;
}

void Container::stopAccepting(){
    this->door->close();
    this->lightSignals->signalProblem();
    this->display->displayFull();
}

void Container::receiveWaste(){
    this->display->displayReceived();
    this->door->close();
}

bool Container::emptyRequested(){
    return this->dashboard->getEmpty();
}

void Container::empty(){
    this->door->empty();
}

bool Container::hasNormalBehaviour(){
    return this->status == NORMAL;
}

void Container::updateDashboard(){
    this->dashboard->communicateStatus(fillPercentage, temperature, this->status==PROBLEM_DETECTED);
}

void Container :: getDashboardInputs(){
    this->dashboard->readRequests();
}