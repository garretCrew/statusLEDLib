#include "statusLEDLib.h"
#include "Arduino.h"

statusLED::statusLED(int pin){
    pinMode(pin,OUTPUT);
    digitalWrite(pin,LOW);
    _pin = pin;
}

void statusLED::update(){
    patternSingle(arrP,plength);
}

void statusLED::setPatternSingle(int pattern[], int lengthArray){
    if (arrP != 0) {
    delete [] arrP;
    }
    arrP = new int [lengthArray];

    for(int i=0; i < lengthArray; i++){
        arrP[i] = pattern[i];
    }
    plength = lengthArray;
}

void statusLED::patternSingle(int pattern[], int lengthArray){
    if(counter < lengthArray) {
        if(milOld == 0){
            milOld = millis();
            digitalWrite(_pin,HIGH);
        }
        if((milOld + pattern[counter]) < millis() ){
            milOld = millis();
            if(counter % 2 == 0){
                digitalWrite(_pin, LOW);
            }
            else{
                digitalWrite(_pin,HIGH);
            }
            counter++;
        }
    }
    else{
        counter = 0;
    }
}