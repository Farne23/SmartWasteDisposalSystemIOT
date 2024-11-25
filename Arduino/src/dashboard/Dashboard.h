#ifndef __DASHBOARD__
#define __DASHBOARD__

#include "MsgService.h"

class Dashboard{
    public:
        Dashboard();
        void setTemperature(double temp, bool alarmOn);
        void setLevel(double level);
    private:
        MsgServiceClass service;
        double temperature;
        double wasteLv;
        bool alarmOn;
        bool temp_defined;
        bool lv_defined;
        void communicate();
};

#endif