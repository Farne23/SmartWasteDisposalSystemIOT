#include "WasteDisposalTask.h"


WasteDisposalTask :: WasteDisposalTask(ContainerWasteDisposal* container){
    this->container = container;
}

void WasteDisposalTask:: initBehaviour(){
    /**
     * Not shared components initliazation here
     */
}

void WasteDisposalTask:: tick(){
    switch (this->status)
    {
    case READY_TO_ACCEPT:
        break;
    case SLEEPING:
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