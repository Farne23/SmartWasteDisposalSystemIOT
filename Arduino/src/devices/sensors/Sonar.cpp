#include "Sonar.h"
#include <Arduino.h>

#define WAIT 3
#define DELAY 5

const float temp = 20,
t_factor = 0.62;
/* velocità del suono supponendo una temperatura di 20°C */
const float vs = 331.45 + temp * t_factor; 

Sonar::Sonar(int trig, int echo) {
    this->trig = trig;
    this->echo = echo;
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
}

double Sonar::sense() {
    // stops the soundwave
    // avoids echo overlap in case of interrupts
    digitalWrite(this->trig,LOW);
    delayMicroseconds(WAIT);

    // emits a soundwave and waits for the rebound
    digitalWrite(this->trig,HIGH);
    delayMicroseconds(5);
    // stops the soundwave
    digitalWrite(this->trig,LOW);
    
    /* Receiving the echo */

    /*
     * tUS is the time needed by the echo to come back, from the 
     * elapsed time, we can calculate the covered distance
     * (pulseIn is a blocking instruction and requires some time)
     */
    float tUS = pulseIn(this->echo, HIGH);
    // / (1000 * 1000) == us -> s
    // / 2 cause tUS is the roundtrip time
    float t = tUS / 1000.0 / 1000.0 / 2;
    // seconds * (meters / seconds) = meters
    float d = t*vs;
    return d;
}