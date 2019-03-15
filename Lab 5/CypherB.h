/**
 CIS22B
 Brian Le

 Header file for CypherB, which is a derived class from Encrypted.
 */
#include "Encrypted.h"
#include <string>
using namespace std;

#ifndef CypherB_h
#define CypherB_h

class CypherB : public Encrypted {
    protected:
        const int shift = 4;
    public:
        CypherB(string, int);
        ~CypherB();
        void decode();
};
#endif
