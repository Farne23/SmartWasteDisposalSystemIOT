#include "dashboard/Dashboard.h"

Dashboard::Dashboard()
{
    MsgService.init();
}

void Dashboard::communicateStatus(double level, double temp, bool alarm)
{
    MsgService.sendMsg(String(level) + ";" + String(temp) +
                       ";" + String(alarm));
}

void Dashboard::readRequests()
{
    if (MsgService.isMsgAvailable())
    {
        Msg *msg = MsgService.receiveMsg();
        String content = msg->getContent();
        if (content == "L")
        {
            this->emptyPressed = true;
        }
        if (content == "T")
        {
            this->repairPressed = true;
        }
        delete msg;
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