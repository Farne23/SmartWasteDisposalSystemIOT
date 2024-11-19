#include "GlobalEnviroment.h"

/*Global status class implementation*/

GlobalEnviroment::GlobalEnviroment(){
  this->status = NORMAL;
  this->lightSignals = new LightSignals(new Led(GREEN_LED_PIN), new Led(RED_LED_PIN));
}

bool GlobalEnviroment::problemDetected(){
  return this->status == PROBLEM_DETECTED;
}

void GlobalEnviroment::signalProblem(){
    this->status = PROBLEM_DETECTED;
}

void GlobalEnviroment::signalNormal(){
  this->status = NORMAL;
}
