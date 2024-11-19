#include "LightSignals.h"
#include "Led.h"

/*Implementation of LigthSignal interface */

LightSignals::LightSignals(Led* greenLed, Led* redLed){
    this->greenLed = greenLed;
    this->redLed = redLed;
}   

void LightSignals::signalAvailability(){
    greenLed->switchOn();
    redLed->switchOff();
}

void LightSignals::signalSleep(){
    greenLed->switchOn();
}

void LightSignals::signalProblem(){
    greenLed->switchOff();
    redLed->switchOn();
}