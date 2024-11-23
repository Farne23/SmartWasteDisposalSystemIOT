#ifndef __CONTAINERWASTEDISPOSAL__
#define __CONTAINERWASTEDISPOSAL__

class ContainerWasteDisposal{
    public:
        virtual bool userDetected() = 0;
        virtual void activateSleepMode() = 0;
        virtual void spill() = 0;
        virtual void signalAvailability() = 0;
        virtual void goToSleep() = 0;
        virtual bool openRequested() =0;
        virtual bool closeRequested() =0;
        virtual bool isFull()=0;
        virtual void receiveWaste()=0;
        virtual void stopAccepting()=0;
        virtual bool emptyRequested()=0;
        virtual void empty()=0;
};

#endif