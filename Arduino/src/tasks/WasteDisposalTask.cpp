#include <Arduino.h>
#include "WasteDisposalTask.h"

WasteDisposalTask :: WasteDisposalTask(ContainerWasteDisposal* container){
    this->container = container;
}

void WasteDisposalTask:: initBehaviour(){
    this->noUserStartTime=millis();
    this->container->signalAvailability();
}

void WasteDisposalTask:: tick(){
    if(this->container->hasNormalBehaviour()){
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
                    this->spillingStartTime = millis();
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
                this->receiveWasteStartTime = millis();
                this->status = RECEIVING_WASTE;
                this->container->receiveWaste();
            }
            break;
        case CONTAINER_FULL:
                if(this->container->emptyRequested() && !this->container->isFull()){
                    emptyingStartTime = millis();
                    this->status = EMPTYING;
                    this->container->empty();
                }
            break;
        case RECEIVING_WASTE:
            if(receiveWasteStartTime+RECEIVING_TIME < millis()){
                    this->status = READY_TO_ACCEPT;
                    this->container->signalAvailability();
                }
            break;
        case EMPTYING:
            if(emptyingStartTime+EMPTY_TIME < millis()){
                    this->status = READY_TO_ACCEPT;
                    this->container->signalAvailability();
                }
            break;
        default:
            break;
        }
    }
}