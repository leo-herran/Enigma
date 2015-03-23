#include "Rotor.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <string>
#include <algorithm>

Rotor::Rotor() {
    this->generateJumbledAlphabet();
}

const std::string Rotor::alphabet = "abcdefghijklmnopqrstuvwxyz";

char Rotor::getEncodedChar(char c) {
    return this->jumbledAlphabet[indexOf(c)];
}

char Rotor::getDecodedChar(char c) {
    return this->alphabet[indexOfJumbled(c)];
}

void Rotor::generateJumbledAlphabet() {
    
    this->jumbledAlphabet = this->alphabet;
    
    //randomly permute elements in jumbledAlphabet
    int temp;
    srand(time(NULL));
    int choice;
    for(int i = 25; i > 0; i--) {
        choice = rand() % i;
        std::swap(jumbledAlphabet.at(choice), jumbledAlphabet.at(i));        
    }  
}

int Rotor::indexOf(char c) {
    for(int i = 0; i < 26; i++) {
        if(alphabet[i] == c) {
            return i; break;
        }
    }
}

int Rotor::indexOfJumbled(char c) {
    for(int i = 0; i < 26; i++) {
        if(jumbledAlphabet[i] == c) {
            return i; break;
        }
    }
}
