#include "TemperatureDetectionTask.h"

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