#include "UserDetector.h"
#include <Arduino.h>

UserDetector::UserDetector(int pin) {
    this->pin = pin;
    pinMode(this->pin, INPUT);
}

bool UserDetector::detect() {
    return digitalRead(this->pin) == HIGH ? true : false;
}