#ifndef __LCDISPLAY__
#define __LCDISPLAY__

#include "TextDisplay2Lines.h"

class LCDisplay: public TextDisplay2Lines {
    public:
        LCDisplay();
        void writeLine(char msg[]);
        void write2Lines(char msg1[], char msg2[]);
    private:
        /*
         * map<string, string> msgs;
         */
};

#endif