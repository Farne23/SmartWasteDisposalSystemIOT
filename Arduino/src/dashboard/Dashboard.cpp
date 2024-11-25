#include "dashboard/Dashboard.h"

/*
 * QUALCOSA NON VA, DASHBOARD DOVREBBE ESSERE USATA DA CONTAINER
 * PER AGGIORNARE I VALORI, MA I TASK DEVONO INTERROGARE PERIODICAMENTE
 * DASHBOARD SUI MESSAGGI CHE ARRIVANO.
 */
Dashboard::Dashboard(){
    this->lv_defined = false;
    this->temp_defined = false;
}

void Dashboard::setTemperature(double temp, bool alarmOn) {
    this->temperature = temp;
    this->alarmOn = alarmOn;
    this->temp_defined = true;
    communicate();
}

void Dashboard::setLevel(double level) {
    this->wasteLv = level;
    this->lv_defined = true;
    communicate();
}

void Dashboard::communicate() {
    if (this->temp_defined && lv_defined) {

    }
}