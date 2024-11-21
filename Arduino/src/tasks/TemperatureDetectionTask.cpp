#include "TemperatureDetectionTask.h"

TemperatureDetectionTask :: TemperatureDetectionTask(ContainerTempDetection* container){
    this->container = container;
}

void TemperatureDetectionTask :: initBehaviour(){
    /**
     * Not shared components initliazation here
     */
}


void TemperatureDetectionTask :: tick(){
    switch (this->status)
    {
    case TEMPERATURE_DETECTION:
        break;
    case TEMPERATURE_EXCEEDING:
        break;
    case SYSTEM_FAILURE:
        break;
    default:
        break;
    }
}