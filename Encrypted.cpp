/**
CIS 22B
Author: Brian Le
This program takes an encrypted file and prints a decrypted output.
Using two different decrypting algorithms, CypherA, and CypherB, it
is able to decrypt a file.

Output is commented at the end of this file.
*/

#include "CypherA.h"
#include "CypherB.h"
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

//constructor
CypherA::CypherA(string filename, int max) : Encrypted(filename, max){}
/**
   Uses the alphabet and the key from the class to decode the file.
   It finds the index of the character in the alphabet and changes
   the value in message to the value from the key.
   */
void CypherA::decode() {
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

CypherA::~CypherA(){};


CypherB::CypherB(string filename, int max) : Encrypted(filename, max) {}
/**
 Uses a "rotational cypher" to decode a message. There is a "shift" that is subtracted
 from the original message to get the new message.
 */
void CypherB::decode() {
    for(int i = 0; i < 1000; i++) {
        if(message[i] == '\0')
            break;
        if(message[i] == ' ' || !isalpha(message[i]))
            continue;
        if(!isalpha(message[i] - shift))
            message[i] = message[i] + (26 - shift);
        else
            message[i] = message[i] - shift;

    }
}

CypherB::~CypherB(){};

/**
OUTPUT:
Enter file name to be decoded with algorithm A: EncB.txt
Decoded message:
gs h ytccepugd esdutwpgvs harvugpkc, nvpk pke yesbeu hsb pke uedgwgesp jye pke yhce met (msvis hy pke yeduep met) pv esdutwp hsb bedutwp pke ceyyhre. vse xeut nhygd ytccepugd esdutwpgvs harvugpkc gy msvis hy pke uvphpgvsha dgwkeu. gs pkgy harvugpkc, pke yesbeu ygcwat "hbby" pke met pv ehdk dkhuhdpeu vq pke daehupezp ceyyhre pv qvuc pke dgwkeupezp. qvu ezhcwae, gq pke met gy 2, "h" ivjab nedvce "d", "n" ivjab nedvce "b, hsb yv vs. pke uedgwgesp ivjab pkes bedutwp pke ceyyhre nt "yjnpuhdpgsr" pke met quvc ehdk dkhuhdpeu vq pke dgwkeupezp pv vnphgs pke vugrgsha ceyyhre.


Enter file name to be decoded with algorithm B: EncB.txt
Decoded message:
in a symmetric encryption algorithm, both the sender and the recipient use the same key (known as the secret key) to encrypt and decrypt the message. one very basic symmetric encryption algorithm is known as the rotational cipher. in this algorithm, the sender simply "adds" the key to each character of the cleartext message to form the ciphertext. for example, if the key is 2, "a" would become "c", "b" would become "d, and so on. the recipient would then decrypt the message by "subtracting" the key from each character of the ciphertext to obtain the original message.

*/
