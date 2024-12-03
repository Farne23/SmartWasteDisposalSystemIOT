#include "dashboard/Dashboard.h"

Dashboard::Dashboard()
{
    this->service.init();
}

void Dashboard::communicateStatus(double level, double temp, bool alarm)
{
    this->service.sendMsg(String(level) + ";" + String(temp) +
                          ";" + String(alarm));
}

void Dashboard::readRequests()
{    
    /*if (service.isMsgAvailable())
    {
        Msg *req = service.receiveMsg();
        // String content = req->getContent();
        this->emptyPressed = req->getContent().equals("Level");
        this->repairPressed = req->getContent().equals("Temperature");
        // free memory
        delete req;
    }*/
    if (Serial.available()) {
        char data = Serial.read();
        this->emptyPressed = data == 'L';
        this->repairPressed = data == 'T';
        delete data;
    }
}

bool Dashboard::getEmpty()
{
    bool tmp = this->emptyPressed;
    this->emptyPressed = false;
    return tmp;
}

bool Dashboard::getRepair()
{
    bool tmp = this->repairPressed;
    this->repairPressed = false;
    return tmp;
}