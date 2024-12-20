#ifndef __TEMPERATUREDETECTIONTASK__
#define __TEMPERATUREDETECTIONTASK__

#include "Task.h"
#include "container/ContainerTempDetection.h"
#include <Arduino.h>

const unsigned int MAX_TEMP = 22;
const unsigned long MAX_TEMP_EXCEEDING_TIME = 5000;

enum TemperatureDetectionTaskStatus
{
    TEMPERATURE_DETECTION,
    TEMPERATURE_EXCEEDING,
    SYSTEM_FAILURE
};

class TemperatureDetectionTask : public Task
{
private:
    TemperatureDetectionTaskStatus status;
    ContainerTempDetection *container;
    long alertStartTime;
    void initBehaviour();

public:
    TemperatureDetectionTask(ContainerTempDetection *container);
    void init();
    void tick();
};

#endif