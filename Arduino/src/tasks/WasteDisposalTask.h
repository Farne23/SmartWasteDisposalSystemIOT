#ifndef __WASTEDISPOSALTASK__
#define __WASTEDISPOSALTASK__

#include "Task.h"
#include "container/ContainerWasteDisposal.h"

enum WasteDisposalTaskStatus{
    READY_TO_ACCEPT,
    WAITING_FOR_USER,
    SLEEPING,
    SPILLING,
    CONTAINER_FULL,
    EMPTYING
};

class WasteDisposalTask : public Task {
    private:
        WasteDisposalTaskStatus status;
        ContainerWasteDisposal* container;
        long noUserStartTime;
        long spillingStartTime;
        void initBehaviour();
    public:
        WasteDisposalTask(ContainerWasteDisposal* container);
        void init();
        void tick();
};

#endif