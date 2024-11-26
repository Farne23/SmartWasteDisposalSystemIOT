#include "GUIUpadateTask.h"

GUIUpdateTask :: GUIUpdateTask (ContainerGUIUpdate* container){
    this->container = container;
}

void GUIUpdateTask  :: initBehaviour(){
    this->status=MONITORING;
}


void GUIUpdateTask :: tick(){
    switch (status)
    {
    case MONITORING:
        this->container->updateDashboard();
        break;
    
    default:
        break;
    }
}