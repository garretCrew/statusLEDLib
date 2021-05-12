#ifndef statusLEDLib_h
#define statusLEDLib_h
#include "Arduino.h"

class statusLED
{
    public:

        statusLED(int pin);

        void patternSingle(int pattern[], int speed); 
        void update();
        void setPatternSingle(int pattern[], int lenghtarray);
        
    private:

        int _pin;
        unsigned long milOld;
        int plength;
        int* arrP = 0;
        int counter = 0;
};

#endif