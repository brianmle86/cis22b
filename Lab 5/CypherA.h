/**
 CIS 22B
 Brian Le

 Header file for CypherA, which is a derived class from Encrypted.
 */
#include "Encrypted.h"
#include <string>
using namespace std;

#ifndef CypherA_h
#define CypherA_h

class CypherA : public Encrypted {
    protected:
        const char key[27] = "iztohndbeqrkglmacsvwfuypjx";
    public:
        CypherA(string, int);
        ~CypherA();
        void decode();
};
#endif


