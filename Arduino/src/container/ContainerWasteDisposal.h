#ifndef __CONTAINERWASTEDISPOSAL__
#define __CONTAINERWASTEDISPOSAL__

class ContainerWasteDisposal{
    public:
        virtual void setReady() = 0;
        virtual void activateSleepMode() = 0;
        virtual void activateSpillMode() = 0;
};

#endif