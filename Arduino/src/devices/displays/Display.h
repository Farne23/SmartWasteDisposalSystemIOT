#ifndef __DISPLAY__
#define __DISPLAY__

#include <map>
#include "utility.h"
#include <string>
#include "LiquidCrystal_I2C.h"
using namespace std;

class Display {
    public:
        Display();
        void displayOpen(); //Press open to enter waste
        void displayClose(); //Press close when done
        void displayReceived(); //Waste received
        void displayFull(); //Container full
        void displayProblem(); //Problem detected
};

#endif