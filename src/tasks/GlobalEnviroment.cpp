#include "GlobalEnviroment.h"

/*Global status class implementation*/

GlobalEnviroment::GlobalEnviroment(){
  this->status = NORMAL;
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
