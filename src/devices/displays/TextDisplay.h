#ifndef __TEXT_DISPLAY__
#define __TEXT_DISPLAY__

//#include <string.h> useless at the moment

/**
 * This interface represents a text display with two lines of text available
 */
class TextDisplay {
    public:
        /**
         * This method writes one line of text at the first line,
         * overwriting the text on the same line.
         */
        virtual void writeLine(char msg[]) = 0;
        /** 
         * This method writes two lines of text on the display
         * overwriting the text on both lines.
         */
        virtual void write2Lines(char msg1[], char msg2[]) = 0;
};

#endif