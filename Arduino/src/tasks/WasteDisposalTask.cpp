#include <Arduino.h>
#include "WasteDisposalTask.h"

WasteDisposalTask ::WasteDisposalTask(ContainerWasteDisposal *container)
{
    this->container = container;
    this->initBehaviour();
}

void WasteDisposalTask::initBehaviour()
{
    this->container->signalAvailability();
    this->status = READY_TO_ACCEPT;
}

void WasteDisposalTask::tick()
{
    if (this->container->hasNormalBehaviour() && !this->container->isSleeping())
    {
        switch (this->status)
        {
        case READY_TO_ACCEPT:
        {
            ///DELETEME
            Serial.println("Sto qua");
            if (this->container->openRequested())
            {
                this->status = SPILLING;
                this->container->spill();
                this->spillingStartTime = millis();
            }
        }
        break;
        case SPILLING:
            if (this->container->isFull())
            {
                this->status = CONTAINER_FULL;
                this->container->stopAccepting();
            }
            else if (this->container->closeRequested() || this->spillingStartTime + SPILL_TIME < millis())
            {
                this->receiveWasteStartTime = millis();
                this->status = RECEIVING_WASTE;
                this->container->receiveWaste();
            }
            break;
        case CONTAINER_FULL:
            if (this->container->emptyRequested() && !this->container->isFull())
            {
                emptyingStartTime = millis();
                this->status = EMPTYING;
                this->container->empty();
            }
            break;
        case RECEIVING_WASTE:
            if (receiveWasteStartTime + RECEIVING_TIME < millis())
            {
                this->status = READY_TO_ACCEPT;
                this->container->signalAvailability();
            }
            break;
        case EMPTYING:
            if (emptyingStartTime + EMPTY_TIME < millis())
            {
                this->status = READY_TO_ACCEPT;
                this->container->signalAvailability();
            }
            break;
        default:
            break;
        }
    }
}