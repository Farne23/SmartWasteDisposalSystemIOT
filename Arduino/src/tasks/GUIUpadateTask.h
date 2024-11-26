#ifndef __GUIUPDATETASK__
#define __GUIUPDATETASK__

#include "Task.h"
#include "container/ContainerGUIUpdate.h"

enum GUIUpdateTStatus{
    MONITORING,
    INPUT_WAITING
};
class GUIUpdateTask: public Task {
    private:
        void initBehaviour();
    public:
        GUIUpdateTask(ContainerGUIUpdate* container);
        void init();
        void tick();
};

#endif