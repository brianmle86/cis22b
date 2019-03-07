#ifndef Encrypted_h
#define Encrypted_h
class Encrypted {
    private:
        char *message;
        const char key[] = "iztohndbeqrkglmacsvwfuypjx";
        bool status;
    public:
        Encrypted();
        Encrypted(string filename, int max)
        bool isEmpty();
        void decode();
        void print();
        ~Encrypted();
};

#endif
