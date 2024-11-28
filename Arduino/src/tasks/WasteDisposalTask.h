#ifndef __WASTEDISPOSALTASK__
#define __WASTEDISPOSALTASK__

#include "Task.h"
#include "container/ContainerWasteDisposal.h"

const unsigned long SPILL_TIME = 5000;
const unsigned long RECEIVING_TIME = 2000;
const unsigned long EMPTY_TIME = 3000;

enum WasteDisposalTaskStatus
{
    READY_TO_ACCEPT,
    SPILLING,
    RECEIVING_WASTE,
    CONTAINER_FULL,
    EMPTYING
};

class WasteDisposalTask : public Task
{
private:
    WasteDisposalTaskStatus status;
    ContainerWasteDisposal *container;
    long spillingStartTime;
    long receiveWasteStartTime;
    long emptyingStartTime;
    void initBehaviour();

public:
    WasteDisposalTask(ContainerWasteDisposal *container);
    void init();
    void tick();
};

#endif