#include "WasteDisposalTask.h"

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