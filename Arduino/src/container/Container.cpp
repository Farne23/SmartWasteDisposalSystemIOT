#include "Container.h"
#include "pins/HwInterfaces.h"

Container::Container(){
    this->tempSensor = new TempSensor(TEMP_SENSOR_PIN);
}

double Container::readTemperature(){
    return this->tempSensor->sense();
}