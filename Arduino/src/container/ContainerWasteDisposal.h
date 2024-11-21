#ifndef __CONTAINERWASTEDISPOSAL__
#define __CONTAINERWASTEDISPOSAL__

class ContainerWasteDisposal{
    public:
        virtual bool userDetected() = 0;
        virtual void activateSleepMode() = 0;
        virtual void signalAvailability() = 0;
        virtual void goToSleep() = 0;
};

#endif