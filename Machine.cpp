#include "Machine.h"
#include <string>
#include <iostream>

Rotor Machine::r1;
Rotor Machine::r2;
Rotor Machine::r3;

std::string Machine::getEncodedString(std::string word) {
    std::string encodedWord;
    
    for(int i = 0; i < word.length(); i++) {
        char c = word.at(i);
        char r1c = this->r1.getEncodedChar(c);
        char r2c = this->r2.getEncodedChar(r1c);
        char r3c = this->r3.getEncodedChar(r2c);
        encodedWord.append(1, r3c);
    }
       
    return encodedWord;
}

std::string Machine::getDecodedString(std::string codeWord) {
    std::string decodedWord;
    for(int i = 0; i < codeWord.length(); i++) {
        char c = codeWord.at(i);
        char r3c = this->r3.getDecodedChar(c);
        char r2c = this->r2.getDecodedChar(r3c);
        char r1c = this->r1.getDecodedChar(r2c);
        decodedWord.append(1, r1c);
    }
       
    return decodedWord;
}
