#include "NewMachine.h"
#include <string>
#include<iostream>


NewMachine::NewMachine() : Machine() {}

std::string NewMachine::getTransformedString(std::string word, bool encode) {
    std::string encodedWord;
    std::cout << "found 0" << "\n";
    if(word == "0") {
        //reset rotors when given end of sentence signal. 
        
        resetRotorDegrees();
        return "0";
    } else {
        for(int i = 0; i < word.length(); i++) {
            char c = word.at(i);
            encodedWord.append(1, transformCharacter(c, encode));
            this->incrementRotorDegrees();
        }

        //increment after each encoded word.  
        this->incrementRotorDegrees();

        return encodedWord;
    }    
}


