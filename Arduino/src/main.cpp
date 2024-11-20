#include <Arduino.h>
#include "tasks/TemperatureDetectionTask.h"
#include "scheduler/Scheduler.h"

Scheduler scheduler;

void setup() {
  scheduler.init(50);

  //Inializzazione della task per il controllo della temperatura
  //Task* tempTask = new TemperatureDetecionTask();
  //tempTask->init(500);
  //scheduler.addTask(tempTask);
}

void loop() {
  scheduler.schedule();
}