#ifndef __TEMPERATUREDETECTIONTASK__
#define __TEMPERATUREDETECTIONTASK__

#include "Task.h"

class TemperatureDetectionTask : public Task {
    private:
        TemperatureDetectionTaskStatus status;
    public:
        void tick();
};

enum TemperatureDetectionTaskStatus{
    TEMPERATURE_DETECTION,
    TEMPERATURE_EXCEEDING,
    PROBLEM_DETECTED
};

#endif