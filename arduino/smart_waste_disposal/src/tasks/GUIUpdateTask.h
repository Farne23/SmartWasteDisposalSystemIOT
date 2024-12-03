#ifndef __GUIUPDATETASK__
#define __GUIUPDATETASK__

#include "Task.h"
#include "container/ContainerGUIUpdate.h"

enum GUIUpdateStatus
{
    MONITORING,
    INPUT_WAITING
};
class GUIUpdateTask : public Task
{
private:
    GUIUpdateStatus status;
    ContainerGUIUpdate *container;
    void initBehaviour();

public:
    GUIUpdateTask(ContainerGUIUpdate *container);
    void init();
    void tick();
};

#endif