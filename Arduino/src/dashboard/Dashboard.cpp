#include "dashboard/Dashboard.h"

Dashboard::Dashboard(){
}

void Dashboard::communicateLv(double level) {;
    this->service.sendMsg(String(level));
}

void Dashboard::communicateTemp(double temp, bool alarmOn) {
    this->service.sendMsg(String(temp) + ";" + String(alarmOn));
}