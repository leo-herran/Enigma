#include <cstdlib>
#include <string>

using namespace std;

#ifndef ROTOR_H
#define	ROTOR_H

class Rotor {
	
public:
	Rotor();
	char getEncodedChar(char c);
	char getDecodedChar(char c);
        int indexOf(char c);
        int indexOfJumbled(char c);
	
private:
	static const string alphabet; //the alphabet in order.  
	string jumbledAlphabet; //permutation of the alphabet. 
        void generateJumbledAlphabet();	
};

#endif	

