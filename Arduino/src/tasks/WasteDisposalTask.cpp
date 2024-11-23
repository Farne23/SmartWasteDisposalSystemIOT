#include <Arduino.h>
#include "WasteDisposalTask.h"

#define SLEEP_TIME 10000
#define SPILL_TIME 5000
#define RECEIVING_TIME 2000


WasteDisposalTask :: WasteDisposalTask(ContainerWasteDisposal* container){
    this->container = container;
}

void WasteDisposalTask:: initBehaviour(){
    this->noUserStartTime=millis();
    this->container->signalAvailability();
}

void WasteDisposalTask:: tick(){
    switch (this->status)
    {
    case READY_TO_ACCEPT:
        if(!this->container->userDetected()){
            this->status = WAITING_FOR_USER;
            this->noUserStartTime = millis();
        }else{
            if(this->container->openRequested()){
                this->status = SPILLING;
                this->container->spill();
                this->spillingStartTIme = millis();
            }
        }
        break;
    case WAITING_FOR_USER:
        if(this->container->userDetected()){
            this->status = READY_TO_ACCEPT;
            this->container->signalAvailability();
        }else{
            if(noUserStartTime+SLEEP_TIME < millis()){
                this->status = SLEEPING;
                this->container->goToSleep();
            }
        }
        break;
    case SLEEPING:
        if(this->container->userDetected()){
            this->status = READY_TO_ACCEPT;
            this->container->signalAvailability();
        }
        break;
    case SPILLING:
        if(this->container->isFull()){
            this->status = EMPTYING;
            this->container->stopAccepting();

        }else if(this->container->closeRequested() || this->spillingStartTime + SPILL_TIME<millis()){
            this->receiveWasteStartTime = millis;
            this->status = RECEVING_WASTE;
            this->container->receiveWaste();
        }
        break;
    case CONTAINER_FULL:
        break;
    case RECEIVING_WASTE:
        if(receiveWasteStartTime+RECEIVING_TIME < millis()){
                this->status = READY_TO_ACCEPT;
                this->container->signalAvailability();
            }
        break;
    case EMPTYING:
        break;
    default:
        break;
    }
}