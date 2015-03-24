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

std::string Machine::getEncodedString(std::string word) {
    std::string encodedWord;
    
    for(int i = 0; i < word.length(); i++) {
        char c = word.at(i);
        
        char r1c = this->r1.getEncodedChar(c, rotorOneDegree);
        char r2c = this->r2.getEncodedChar(r1c, rotorTwoDegree);
        char r3c = this->r3.getEncodedChar(r2c, rotorThreeDegree);
        char reflectedr3c = this->reflector.getEncodedChar(r3c, 0); //reflector can't rotate
        char r3dc = this->r3.getDecodedChar(reflectedr3c, rotorThreeDegree);
        char r2dc = this->r2.getDecodedChar(r3dc, rotorTwoDegree);
        char r1dc = this->r1.getDecodedChar(r2dc, rotorOneDegree);
        encodedWord.append(1, r1dc);
        
        //rotate a rotor by one place after encoding a char. 
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
    
    //reset rotors now that we are done encoding. 
    rotorOneDegree = 0;
    rotorTwoDegree = 0;
    rotorThreeDegree = 0;
  
    return encodedWord;
}

std::string Machine::getDecodedString(std::string codeWord) {
    std::string decodedWord;
    
    for(int i = 0; i < codeWord.length(); i++) {
        char c = codeWord.at(i);
        char r1c = this->r1.getEncodedChar(c, rotorOneDegree);
        char r2c = this->r2.getEncodedChar(r1c, rotorTwoDegree);
        char r3c = this->r3.getEncodedChar(r2c, rotorThreeDegree);
        char reflectedr3c = this->reflector.getDecodedChar(r3c, 0); //we use 
        //decode here, not encode. This makes the reflector a symmetric rotor. 
        char r3dc = this->r3.getDecodedChar(reflectedr3c, rotorThreeDegree);
        char r2dc = this->r2.getDecodedChar(r3dc, rotorTwoDegree);
        char r1dc = this->r1.getDecodedChar(r2dc, rotorOneDegree);
        decodedWord.append(1, r1dc);
        
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
    
    //reset rotors now that we are done decoding. 
    rotorOneDegree = 0;
    rotorTwoDegree = 0;
    rotorThreeDegree = 0;
    
    return decodedWord;
}
