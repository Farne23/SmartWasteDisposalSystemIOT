#include "GlobalEnviroment.h"

/*Global status class implementation*/

GlobalEnviroment::GlobalEnviroment(){
  this->status = NORMAL;
  this->lightSignals = new LightSignals(new Led(GREEN_LED_PIN), new Led(RED_LED_PIN));
  this->init();
}

/*Function used to setup the part of the system shared between the FSMS in the conditions 
we want to have it at the start of the system.  */
void GlobalEnviroment::init(){
    this->signalNormal();
    this->signalAvailability_lights();
}

bool GlobalEnviroment::problemDetected(){
  return this->status == PROBLEM_DETECTED;
}

void GlobalEnviroment::signalProblem(){
    this->status = PROBLEM_DETECTED;
    this->lightSignals->signalProblem();
}

void GlobalEnviroment::signalNormal(){
  /** FUNZIONE CHIAMTA DALLA FSM DI DETECION GUAI, cancellabile solo se non 
   * è necessario mantenere memoria dello stato passato del container
   */
  this->status = NORMAL;
}

void GlobalEnviroment::signalAvailability_lights(){
  this->lightSignals->signalAvailability();
};
void GlobalEnviroment::signalSleep_lights(){
  this->lightSignals->signalSleep();
};   

void GlobalEnviroment::signalProblem_lights(){
  this->lightSignals->signalProblem();
}; 
