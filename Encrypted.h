#include <string>
using namespace std;
#ifndef Encrypted_h
#define Encrypted_h
class Encrypted {
    private:
        char *message;
        const char key[27] = "iztohndbeqrkglmacsvwfuypjx";
        bool status;
    public:
        Encrypted();
        Encrypted(std::string filename, int max);
        bool isEmpty();
        void decode();
        void print();
        ~Encrypted();
};

#endif
