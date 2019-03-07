#include "Encrypted.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
Encrypted::Encrypted(string filename, int max) {
    status = true;
    ifstream inFile;
    inFile.open(filename);
    if(!inFile) {
        cout << "could not open file\n";
        exit(1);
    }
    message = new char[max + 1];
    char x;
    char first_ch;
    while(inFile >> x) {
        status = false;
        int i;
        message[i] = x;
        i++;
    }
}

bool Encrypted::isEmpty() {
    return status;
}

void Encrypted::decode() {
    char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
    char ch;
    //compare key to message
        //find index of alphabet in file;
    while(inFile >> ch) {
        
    }
        //compare to key
        //swap values
        //store in message char array
}

void Encrypted::print() {

}
Encrypted::~Encrypted() {
    delete[] message;
}
