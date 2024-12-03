#ifndef __CONTAINERSLEEPMODE__
#define __CONTAINERSLEEPMODE__

class ContainerSleepModeManager{
    public:
        virtual bool userDetected() = 0;
        virtual void goToSleep() = 0;
        virtual void wakeUp() = 0;
};

#endif