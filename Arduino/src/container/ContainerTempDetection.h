#ifndef __CONTAINERTEMPDETECION__
#define __CONTAINERTEMPDETECTION__

class ContainerTempDetection{
    public:
        virtual bool problemDetected() = 0;
        virtual void signalProblem() = 0;
        virtual void signalNormal() = 0;
};

#endif