#include "Container.h"
#include "pins/HwInterfaces.h"

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
    this->door->close();
    this->lightSignals->signalAvailability();
    this->display->displayReadyToOpen();
}

void Container::goToSleep(){
    this->lightSignals->signalSleep();
}

bool Container::openRequested(){
    return this->buttonPanel->openRequested();
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