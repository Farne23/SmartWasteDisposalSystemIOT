#include "dashboard/Dashboard.h"

Dashboard::Dashboard(){
}

void Dashboard::communicateStatus(double level, double temp, bool alarm) {
    this->service.sendMsg(String(level) + ";" + String(temp) +
        ";" + String(alarm));
}

void Dashboard::readRequests() {
    if (service.isMsgAvailable()) {
        Msg * req = service.receiveMsg();
        // BISOGNA CAPIRE SE GETCONTENT() TORNA UNA STRINGA
        // O ALTRO.
        this->emptyPressed = req->getContent() == "L";
        this->repairPressed = req->getContent() == "T";
    }
}

bool Dashboard::getEmpty() {
    bool tmp = this->emptyPressed;
    this->emptyPressed = false;
    return tmp;
}

bool Dashboard::getRepair() {
    bool tmp = this->repairPressed;
    this->repairPressed = false;
    return tmp;
}