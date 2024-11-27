#ifndef __TEMPERATUREDETECTIONTASK__
#define __TEMPERATUREDETECTIONTASK__

#include "Task.h"
#include "container/ContainerTempDetection.h"

const unsigned int MAX_TEMP = 20;
const unsigned long MAX_TEMP_EXCEEDING_TIME = 3000;

enum TemperatureDetectionTaskStatus{
    TEMPERATURE_DETECTION,
    TEMPERATURE_EXCEEDING,
    SYSTEM_FAILURE
};

class TemperatureDetectionTask : public Task {
    private:
        TemperatureDetectionTaskStatus status;
        ContainerTempDetection* container;
        long alertStartTime;
        void initBehaviour();
    public:
        TemperatureDetectionTask(ContainerTempDetection* container);
        void init();
        void tick();
};

#endif