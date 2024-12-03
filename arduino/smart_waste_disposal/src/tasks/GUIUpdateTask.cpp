#include "GUIUpdateTask.h"
#include "Arduino.h"

GUIUpdateTask ::GUIUpdateTask(ContainerGUIUpdate *container)
{
    this->container = container;
    this->initBehaviour();
}

void GUIUpdateTask ::initBehaviour()
{
    this->status = MONITORING;
}

void GUIUpdateTask ::tick()
{
    if (!this->container->isSleeping())
    {
        this->container->updateDashboard();
        switch (status)
        {
        case MONITORING:
            if (!this->container->hasNormalBehaviour() || this->container->isEmptyNeeded())
            {
                this->status = INPUT_WAITING;
            }
            break;
        case INPUT_WAITING:
            this->container->getDashboardInputs();
            if (this->container->hasNormalBehaviour() && !this->container->isEmptyNeeded())
            {
                this->status = MONITORING;
            }
            break;

        default:
            break;
        }
    }
}