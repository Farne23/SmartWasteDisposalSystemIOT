#ifndef __WASTEDISPOSALTASK__
#define __WASTEDISPOSALTASK__

#include "Task.h"

class WasteDisposalTask : public Task {
    private:
        WasteDisposalTaskStatus status;
    public:
        void tick();
};

enum WasteDisposalTaskStatus{
    READY_TO_ACCEPT,
    SLEEPING,
    SPILLING,
    CONTAINER_FULL,
    EMPTYING
};

#endif