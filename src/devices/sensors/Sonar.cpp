#include "Sonar.h"
#include <Arduino.h>

#define VS 6641.4

Sonar::Sonar(int trig, int echo) {
    this->trig = trig;
    this->echo = echo;
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);  
}

double Sonar::sense() {
    /* Triggering stage: sending the impulse */

    //in generale, dato che il sonar viene disattivato due volte,
    //questa disattivazione è un po' inutile.
    digitalWrite(this->trig, LOW);
    //ferma l'onda
    delayMicroseconds(3);
    //aspetta l'eco
    digitalWrite(this->trig, HIGH);
    //manda il segnale per 5 microsecondi
    delayMicroseconds(5);
    digitalWrite(this->trig, LOW);
    
    /* Receiving the echo */

    // è il numero di microsecondi che sono passati per ricevere
    // il segnale (a partire dall'invio), dai microsecondi noi ci calcoliamo la distanza.
    float tUS = pulseIn(this->echo, HIGH);
    /*N.B. pulseIn è un'istruzione BLOCCANTE e RICHIEDE TEMPO*/
    // lo converto in secondi, diviso due perchè il tempo deve comprendere sia il tempo di andata
    //che di ritorno
    float t = tUS / 1000.0 / 1000.0 / 2;
    float d = t * VS;
    return d;
}