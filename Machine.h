#include "Rotor.h"
#include <string>

using namespace std;

#ifndef MACHINE_H
#define	MACHINE_H

class Machine {   
    
    /* Degrees of rotation for the three rotors (0 to 25). */
    int rotorOneDegree;
    int rotorTwoDegree;
    int rotorThreeDegree;
    
public: 
    Machine();
    /* Retrieves encoded/decoded (depending on value of encode) string of the 
     given string word. */
    std::string getTransformedString(std::string word, bool encode);
    
protected:
    /* Rotors are static because all enigma machines should share the same 
     * rotors, but in this implementation every Machine will be equipped with
     * different rotors upon instantiation. For every instance of a Machine 
     * to share the same rotors would require hard-coding them. */
    static Rotor r1;
    static Rotor r2;
    static Rotor r3;
    
    /* A symmetric rotor (meaning if a maps to b then b maps to a). */
    static Rotor reflector;
    
    /* Retrieves the encoded/decoded form of a single character. */
    char transformCharacter(char c, bool encode);
    
    void incrementRotorDegrees();
    void resetRotorDegrees();
};

#endif	

