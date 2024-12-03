#ifndef __DASHBOARD__
#define __DASHBOARD__

#include "MsgService.h"

class Dashboard{
    public:
        Dashboard();
        void communicateStatus(double level, double temp, bool alarmOn);
        void readRequests();
        bool getEmpty();
        bool getRepair();
    private:
        bool emptyPressed;
        bool repairPressed;
};

#endif