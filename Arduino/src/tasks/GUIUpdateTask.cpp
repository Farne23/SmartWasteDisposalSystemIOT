#include "GUIUpdateTask.h"

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
            if (!this->container->hasNormalBehaviour() || this->container->isFull())
            {
                this->status = INPUT_WAITING;
            }
            break;
        case INPUT_WAITING:
            if (this->container->hasNormalBehaviour() && !this->container->isFull())
            {
                this->status = MONITORING;
            }
            this->container->getDashboardInputs();
            break;

        default:
            break;
        }
    }
}