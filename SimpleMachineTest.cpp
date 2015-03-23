#include "Rotor.h"
#include "Machine.h"
#include<iostream>

using namespace std;

int main() {
    //A simple test for a three-rotor pseudo enigma machine. 
    
    Machine m;
    string word = "leo";
    string codeword = m.getEncodedString(word);
    cout << codeword << "\n";
    string wordback = m.getDecodedString(codeword);
    cout << wordback;
}