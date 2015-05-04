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
        void setSecretAlphabet(string secretAlphabet);
        
        /* Returns the index of c in the regular alphabet. */
        int indexOf(char c);
        
        /* Returns the index of c in the jumbled alphabet. */
        int indexOfJumbled(char c);
	
private:
        /* The alphabet in order. */
	static const string alphabet;
        
        /* permutation of the alphabet. */
	string jumbledAlphabet;  
        
        void generateJumbledAlphabet();	
        
        /* Returns (a%b) in the range (0, b-1). */
        int positiveMod(int a, int b);
};

#endif	

