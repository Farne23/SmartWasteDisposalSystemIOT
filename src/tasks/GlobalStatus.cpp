#include "GlobalStatus.h"

/*Global status class implementation*/

GlobalStatus::GlobalStatus(){
  this->status = NORMAL;
}

bool GlobalStatus::problemDetected(){
  return this->status == PROBLEM_DETECTED;
}

void GlobalStatus::signalProblem(){
    this->status = PROBLEM_DETECTED;
}

void GlobalStatus::signalNormal(){
  this->status = NORMAL;
}
