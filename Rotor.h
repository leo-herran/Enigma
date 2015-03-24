#include <cstdlib>
#include <string>

using namespace std;

#ifndef ROTOR_H
#define	ROTOR_H

class Rotor {
    
public:
	Rotor();
	char getEncodedChar(char c, int rotationDegree);
	char getDecodedChar(char c, int rotationDegree);
        int indexOf(char c);
        int indexOfJumbled(char c);
	
private:
	static const string alphabet; //the alphabet in order.  
	string jumbledAlphabet; //permutation of the alphabet. 
        void generateJumbledAlphabet();	
        int positiveMod(int a, int b);
};

#endif	

