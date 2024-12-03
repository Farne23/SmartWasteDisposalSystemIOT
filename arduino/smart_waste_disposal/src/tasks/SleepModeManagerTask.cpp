#include <Arduino.h>
#include "SleepModeManagerTask.h"

SleepModeManagerTask ::SleepModeManagerTask(ContainerSleepModeManager *container)
{
    this->container = container;
    this->initBehaviour();
}

void SleepModeManagerTask::initBehaviour()
{
    this->status = USER_DETECTED;
}

void SleepModeManagerTask::tick()
{
    switch (this->status)
    {
    case USER_DETECTED:
        if (!this->container->userDetected())
        {
            this->status = WAITING_FOR_USER;
            this->noUserStartTime = millis();
        }
        break;
    case WAITING_FOR_USER:
        if (this->container->userDetected())
        {
            this->status = USER_DETECTED;
        }
        else if (noUserStartTime + SLEEP_TIME < millis())
        {
            this->status = SLEEPING;
            this->container->goToSleep();
        }
        break;
    case SLEEPING:
        if (this->container->userDetected())
        {
            this->container->wakeUp();
            this->status = USER_DETECTED;
        }
        break;
    default:
        break;
    }
}