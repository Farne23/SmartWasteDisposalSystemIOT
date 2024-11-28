#ifndef __CONTAINERGUIUPDATE__
#define __CONTAINERGUIUPDATE__

class ContainerGUIUpdate{
    public:
        virtual void updateDashboard() = 0;
        virtual bool isFull() = 0;
        virtual void getDashboardInputs() = 0;
        virtual bool hasNormalBehaviour() = 0;
        virtual bool isSleeping() = 0;
};

#endif