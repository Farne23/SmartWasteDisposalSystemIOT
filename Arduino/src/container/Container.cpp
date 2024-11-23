#include "Container.h"
#include "pins/HwInterfaces.h"

#define CONTAINER_FULL_DISTANCE 0.15 //threshold rappresenting the distance  the sonar has to sense in order to consider the container full
#define CONTAINER_EMPTY_DISTANCE 0.25

Container::Container(){
    this->tempSensor = new TempSensor(TEMP_SENSOR_PIN);
    this->lightSignals = new LightSignals(new Led(GREEN_LED_PIN), new Led(RED_LED_PIN));
    this->userDetector = new UserDetector(USER_DETECTOR_PIN);
    this->status=NORMAL;
}

double Container::readTemperature(){
    return this->tempSensor->sense();
}

void Container::signalProblem(){
    this->status=PROBLEM_DETECTED;
    this->lightSignals->signalProblem();
}

bool Container::isFixed(){
    return this->status==NORMAL;
}

bool Container::userDetected(){
    return this->userDetector->detect();
}


void Container::signalAvailability(){
    //this->door->close();
    this->lightSignals->signalAvailability();
    this->display->displayReadyToOpen();
}

void Container::goToSleep(){
    this->lightSignals->signalSleep();
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
    return this->fillPercentage()>=100;
}

double Container::fillPercentage(){
    return ((this->sonar->sense()-CONTAINER_EMPTY_DISTANCE)/(CONTAINER_FULL_DISTANCE-CONTAINER_EMPTY_DISTANCE))*100;
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
    ///Notifica di empty
}

void Container::empty(){
    this->door->empty();
}

bool Container::hasNormalBehaviour(){
    return this->status == NORMAL;
}