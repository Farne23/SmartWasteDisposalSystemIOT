#include <Arduino.h>
#include "tasks/TemperatureDetectionTask.h"
#include "tasks/WasteDisposalTask.h"
#include "tasks/SleepModeManagerTask.h"
#include "tasks/GUIUpdateTask.h"
#include "container/Container.h"
#include "scheduler/Scheduler.h"

Scheduler scheduler;
Container* container;

void setup() {

  container = new Container();

  // //Inializzazione della task per il controllo della temperatura
  // Task* tempTask = new TemperatureDetectionTask(static_cast<ContainerTempDetection*>(container));
  // tempTask->init(50);

  //Inializzazione della task per il controllo del container
  Task* wasteDisposalTask = new WasteDisposalTask(static_cast<ContainerWasteDisposal*>(container));
  wasteDisposalTask->init(50);

  Task* sleepModeManagerTask = new SleepModeManagerTask(static_cast<ContainerSleepModeManager*>(container));
  sleepModeManagerTask->init(50);

  //Inializzazione della task per l'aggiornamento della gui
  // Task* guiUpdateTask = new GUIUpdateTask(static_cast<ContainerGUIUpdate*>(container));
  // guiUpdateTask->init(150);

  // //Aggiunta delle task allo scheduler
  // scheduler.addTask(tempTask);
  // scheduler.addTask(wasteDisposalTask);
  // scheduler.addTask(guiUpdateTask);

  //Inizializzazione scheduler
  scheduler.init(50);


}

void loop() {
  scheduler.schedule();
}