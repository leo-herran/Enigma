#include "Machine.h"
#include <string>

#ifndef NEWMACHINE_H
#define	NEWMACHINE_H

class NewMachine:public Machine {
public:    
    NewMachine();
    virtual std::string getTransformedString(std::string word, bool encode) override;
};

#endif	/* NEWMACHINE_H */

