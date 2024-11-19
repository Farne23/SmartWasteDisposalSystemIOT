#ifndef __TEMPERATUREDETECTIONTASK__
#define __TEMPERATUREDETECTIONTASK__

#include "Task.h"

enum TemperatureDetectionTaskStatus{
    TEMPERATURE_DETECTION,
    TEMPERATURE_EXCEEDING,
    SYSTEM_FAILURE
};

class TemperatureDetectionTask : public Task {
    private:
        TemperatureDetectionTaskStatus status;
    public:
        void tick();
};

#endif