/**
CIS 22B
Author: Brian Le
This program takes an encrypted file and prints a decrypted output.
*/

#include "Encrypted.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;
//constructor
Encrypted::Encrypted(string filename, int max) {
    status = true; 
    ifstream inFile;
    inFile.open(filename);
    if(!inFile) {
        cout << "could not open file\n";
        exit(1);
    }
    message = new char[max];
    
    int i = 0;
    char x;
    while(inFile >> std::noskipws >> x) {
        status = false; //if file can be read, it is not empty
        message[i] = x;
        i++;
    }
    
    inFile.close();
    //successfully put into c-string array at this point
}
/**
 Returns status, to tell if file is empty or not
 */
bool Encrypted::isEmpty() {
    return status;
}

/**
 Uses the alphabet and the key from the class to decode the file.
 It finds the index of the character in the alphabet and changes
 the value in message to the value from the key.
 */
void Encrypted::decode() {
    char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
    
    int index;
    for(int i = 0; i < 1000; i++) {
        if(message[i] == '\0')
            break;
        if(message[i] == ' ' || !isalpha(message[i]))
            continue;
        for(int j = 0; j < 27; j++) {
            if(message[i] == alphabet[j])
                index = j;
        }
        message[i] = key[index];
    }
}

void Encrypted::print() {
    for(int i = 0; i < 1000; i++) {
        if(message[i] == '\0')
            break;
        else
            cout << message[i];
        

    }
    cout << endl;
}
//destructor
Encrypted::~Encrypted() {
    delete[] message;
}

/**
OUTPUT:
Enter file name: Encrypted.txt
encryption is the name given to the process of applying an algorithm to a message, which scrambles the data in it-making it very difficult and time consuming, if not practically impossible, to deduce the original given only the encoded data. inputs to the algorithm typically involve additional secret data called keys, which prevents the message from being decoded-even if the algorithm is publicly known.
*/
