/**
 CIS22B
 Brian Le

 Header file for class Encrypted.
 */
#include <string>
using namespace std;
#ifndef Encrypted_h
#define Encrypted_h
class Encrypted {
    protected:
        char *message;
        bool status;
    public:
        Encrypted();
        Encrypted(std::string filename, int max);
        bool isEmpty();
        virtual void decode() = 0;
        void print();
        ~Encrypted();
};

#endif
