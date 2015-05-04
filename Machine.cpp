#include "Machine.h"
#include <string>
#include <iostream>

using namespace std;

Rotor Machine::r1;
Rotor Machine::r2;
Rotor Machine::r3;
Rotor Machine::reflector;

string secretR1 = "dgnotpubfkacivhlsmrjwyxzeq";
string secretR2 = "lompwdzfsravkejnixtgchyqbu";
string secretR3 = "qkgslyfbphotwuraemnczdijvx";
string secretReflector = "lrufxmntzevkphiqodaywbjgsc";

Machine::Machine() {
    this->rotorOneDegree = 0;
    this->rotorTwoDegree = 0;
    this->rotorThreeDegree = 0;
}

Machine::Machine(bool secretModeFlag) {
    r1.setSecretAlphabet(secretR1);
    r2.setSecretAlphabet(secretR2);
    r3.setSecretAlphabet(secretR3);
    reflector.setSecretAlphabet(secretReflector);
    this->rotorOneDegree = 0;
    this->rotorTwoDegree = 0;
    this->rotorThreeDegree = 0;
}

void Machine::resetRotorDegrees() {
    rotorOneDegree = 0;
    rotorTwoDegree = 0;
    rotorThreeDegree = 0;
}

/* Increments the first rotor by one. The second rotor is incremented when 
 * the first makes a full rotation and the third is incremented when the second
 * makes a full rotation. */
void Machine::incrementRotorDegrees() {
    if(rotorOneDegree == 26) {
        if(rotorTwoDegree == 26) {
            if(rotorThreeDegree == 26) {
                /* All three rotors have made a full rotation, so
                 * reset them completely. */
                resetRotorDegrees();
            } else {
                rotorThreeDegree++;
                rotorTwoDegree = 1;
            }
        } else {
            rotorTwoDegree++;
            rotorOneDegree = 1;
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
        /* Pass in 0 for rotation degree because the reflector doesn't rotate. */
        reflectedr3c = this->reflector.getEncodedChar(r3c, 0); 
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
    
    if(word == "0") {
        /* Reset rotors when given end of sentence signal ("0"). We are 
         * done encoding the sentence. */
        resetRotorDegrees();
        return "0";
    } else {
    
        for(int i = 0; i < word.length(); i++) {
            char c = word.at(i);
            encodedWord.append(1, transformCharacter(c, encode));
            incrementRotorDegrees();
        }
        
        return encodedWord;
    }
};
