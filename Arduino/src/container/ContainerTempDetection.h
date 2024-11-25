#ifndef __CONTAINERTEMPDETECION__
#define __CONTAINERTEMPDETECTION__

class ContainerTempDetection{
    public:
        virtual void signalProblem() = 0;
        virtual bool isFixed() = 0;
        virtual double readTemperature() = 0;
};

#endif