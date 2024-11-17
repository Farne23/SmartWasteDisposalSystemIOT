#include "TempSensor.h"
#include <Arduino.h>

TempSensor::TempSensor(int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);  
}

double TempSensor::sense() {
    int adc;
    double temp;
    /* Read temperature */
    adc = analogRead(pin);
    /* Conversion from 0-1023 to 0-5000mV*/
    temp = adc * 4.88;
    /* lm-35 sensor has a 10mV/C° factor */
    temp /= 10;
    return temp;
}