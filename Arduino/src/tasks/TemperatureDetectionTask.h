#ifndef __TEMPERATUREDETECTIONTASK__
#define __TEMPERATUREDETECTIONTASK__

#include "Task.h"
#include "container/ContainerTempDetection.h"

enum TemperatureDetectionTaskStatus{
    TEMPERATURE_DETECTION,
    TEMPERATURE_EXCEEDING,
    SYSTEM_FAILURE
};

class TemperatureDetectionTask : public Task {
    private:
        TemperatureDetectionTaskStatus status;
        ContainerTempDetection* container;
        void initBehaviour();
    public:
        TemperatureDetectionTask(ContainerTempDetection* container);
        void init();
        void tick();
};

#endif