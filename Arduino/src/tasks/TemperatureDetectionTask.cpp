#include "TemperatureDetectionTask.h"

TemperatureDetectionTask ::TemperatureDetectionTask(ContainerTempDetection *container)
{
    this->container = container;
    this->initBehaviour();
}

void TemperatureDetectionTask ::initBehaviour()
{
    this->status = TEMPERATURE_DETECTION;
}

void TemperatureDetectionTask ::tick()
{
    if (!this->container->isSleeping())
    {
        switch (this->status)
        {
        case TEMPERATURE_DETECTION:
            if (this->container->readTemperature() > MAX_TEMP)
            {
                this->alertStartTime = millis();
                this->status = TEMPERATURE_EXCEEDING;
            }
            break;
        case TEMPERATURE_EXCEEDING:
            if (this->container->readTemperature() > MAX_TEMP)
            {
                if (this->alertStartTime + MAX_TEMP_EXCEEDING_TIME < millis())
                {
                    this->status = SYSTEM_FAILURE;
                    this->container->signalProblem();
                }
            }
            else
            {
                this->status = TEMPERATURE_DETECTION;
            }
            break;
        case SYSTEM_FAILURE:
            if (this->container->isFixed())
            {
                this->status = TEMPERATURE_DETECTION;
                this->container->resetLights();
            }
            break;
        default:
            break;
        }
    }
}