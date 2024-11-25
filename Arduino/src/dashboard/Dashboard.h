#ifndef __DASHBOARD__
#define __DASHBOARD__

#include "MsgService.h"

class Dashboard{
    public:
        Dashboard();
        void communicateTemp(double temp, bool alarmOn);
        void communicateLv(double level);
    private:
        MsgServiceClass service;
};

#endif