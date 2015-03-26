#include "Machine.h"
#include <string>
#include <iostream>


Rotor Machine::r1;
Rotor Machine::r2;
Rotor Machine::r3;
Rotor Machine::reflector;

Machine::Machine() {
    this->rotorOneDegree = 0;
    this->rotorTwoDegree = 0;
    this->rotorThreeDegree = 0;
}

void Machine::resetRotorDegrees() {
    rotorOneDegree = 0;
    rotorTwoDegree = 0;
    rotorThreeDegree = 0;
}

void Machine::incrementRotorDegrees() {
    if(rotorOneDegree == 26) {
            if(rotorTwoDegree == 26) {
                if(rotorThreeDegree != 26) {
                    rotorThreeDegree++;
                }
            } else {
                rotorTwoDegree++;
            }
    } else {
        rotorOneDegree++;
    }
}

char Machine::transformCharacter(char c, bool encode) {
    char r1c = r1.getEncodedChar(c, rotorOneDegree);
    char r2c = r2.getEncodedChar(r1c, rotorTwoDegree);
    char r3c = r3.getEncodedChar(r2c, rotorThreeDegree);
    char reflectedr3c;
    if(encode) {
        reflectedr3c = this->reflector.getEncodedChar(r3c, 0); //reflector can't rotate
    } else {
        reflectedr3c = this->reflector.getDecodedChar(r3c, 0); 
    }
    char r3dc = r3.getDecodedChar(reflectedr3c, rotorThreeDegree);
    char r2dc = r2.getDecodedChar(r3dc, rotorTwoDegree);
    char r1dc = r1.getDecodedChar(r2dc, rotorOneDegree);
    return r1dc; 
}

std::string Machine::getTransformedString(std::string word, bool encode) {
    std::string encodedWord;
    
    for(int i = 0; i < word.length(); i++) {
        char c = word.at(i);
        encodedWord.append(1, transformCharacter(c, encode));
        incrementRotorDegrees();
    }
    
    //reset rotors now that we are done encoding. 
    resetRotorDegrees();
  
    return encodedWord;
};


