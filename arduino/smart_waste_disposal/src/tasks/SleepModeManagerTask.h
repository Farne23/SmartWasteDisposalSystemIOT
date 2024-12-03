#ifndef __SLEEPMODEMANAGERTASK__
#define __SLEEPMODEMANAGERTASK__

#include "Task.h"
#include "container/ContainerSleepModeManager.h"

const unsigned long SLEEP_TIME = 14000;

enum SleepModeStatus
{
    USER_DETECTED,
    WAITING_FOR_USER,
    SLEEPING,
};

class SleepModeManagerTask : public Task
{
private:
    SleepModeStatus status;
    ContainerSleepModeManager *container;
    unsigned long noUserStartTime;
    void initBehaviour();

public:
    SleepModeManagerTask(ContainerSleepModeManager *container);
    void init();
    void tick();
};

#endif