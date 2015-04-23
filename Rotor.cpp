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

char Rotor::getEncodedChar(char c, int rotationDegree) {
    return this->jumbledAlphabet[positiveMod((indexOf(c) - rotationDegree), 26)];
}

char Rotor::getDecodedChar(char c, int rotationDegree) {
    return this->alphabet[positiveMod((indexOfJumbled(c) + rotationDegree), 26)];
}

/* Generates jumpedAlphabet by randomly permuting elements in the 
 regular alphabet. */
void Rotor::generateJumbledAlphabet() {
    this->jumbledAlphabet = this->alphabet;
   
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
            return i; 
        }
    }
}

int Rotor::indexOfJumbled(char c) {
    for(int i = 0; i < 26; i++) {
        if(jumbledAlphabet[i] == c) {
            return i; 
        }
    }
}

int Rotor::positiveMod(int a, int b) {
    return ((a%b) + b) % b;
}