#include "Container.h"
#include "pins/HwInterfaces.h"

Container::Container(){
    this->tempSensor = new TempSensor(TEMP_SENSOR_PIN);
    this->lightSignals = new LightSignals(new Led(GREEN_LED_PIN), new Led(RED_LED_PIN));
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