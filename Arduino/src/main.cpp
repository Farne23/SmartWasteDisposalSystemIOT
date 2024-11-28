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
  Serial.begin(9600);
  //Container intitialization
  container = new Container();
  //Scheduler initialization
  scheduler.init(50);

  //Inializzazione della task per il controllo della temperatura
  Task* tempTask = new TemperatureDetectionTask(static_cast<ContainerTempDetection*>(container));
  tempTask->init(100);

  //Inializzazione della task per il controllo del container
  Task* wasteDisposalTask = new WasteDisposalTask(static_cast<ContainerWasteDisposal*>(container));
  wasteDisposalTask->init(50);

  Task* sleepModeManagerTask = new SleepModeManagerTask(static_cast<ContainerSleepModeManager*>(container));
  sleepModeManagerTask->init(200);

  //Inializzazione della task per l'aggiornamento della gui
  Task* guiUpdateTask = new GUIUpdateTask(static_cast<ContainerGUIUpdate*>(container));
  guiUpdateTask->init(150);

  //Aggiunta delle task allo scheduler
  scheduler.addTask(tempTask);
  scheduler.addTask(wasteDisposalTask);
  scheduler.addTask(sleepModeManagerTask);
  scheduler.addTask(guiUpdateTask);
}

void loop() {
  scheduler.schedule();
}