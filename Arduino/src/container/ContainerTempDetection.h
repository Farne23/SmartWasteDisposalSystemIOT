#ifndef __CONTAINERTEMPDETECTION__
#define __CONTAINERTEMPDETECTION__

class ContainerTempDetection{
    public:
        virtual void signalProblem() = 0;
        virtual bool isFixed() = 0;
        virtual double readTemperature() = 0;
        virtual bool isSleeping() = 0;
        virtual void resetLights() = 0;
};

#endif