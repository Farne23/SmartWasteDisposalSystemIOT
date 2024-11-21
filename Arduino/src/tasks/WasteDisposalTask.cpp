#include <Arduino.h>
#include "WasteDisposalTask.h"

#define SLEEP_TIME 10000


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
            this->noUserStartTime = millis();
            this->status = WAITING_FOR_USER;
        }else{
            ///Verifica apertura bottone
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
        break;
    case CONTAINER_FULL:
        break;
    case EMPTYING:
        break;
    default:
        break;
    }
}