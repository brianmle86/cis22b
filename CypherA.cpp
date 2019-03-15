/**
 CIS 22B
 Brian Le

 Contains function definitions for CypherA.
 Output of entire program commented at bottom.
 */
#include "CypherA.h"
#include <string>
using namespace std;
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

/**
 Enter file name to be decoded with algorithm A: EncB.txt
Decoded message: 
gs h ytccepugd esdutwpgvs harvugpkc, nvpk pke yesbeu hsb pke uedgwgesp jye pke yhce met (msvis hy pke yeduep met) pv esdutwp hsb bedutwp pke ceyyhre. vse xeut nhygd ytccepugd esdutwpgvs harvugpkc gy msvis hy pke uvphpgvsha dgwkeu. gs pkgy harvugpkc, pke yesbeu ygcwat "hbby" pke met pv ehdk dkhuhdpeu vq pke daehupezp ceyyhre pv qvuc pke dgwkeupezp. qvu ezhcwae, gq pke met gy 2, "h" ivjab nedvce "d", "n" ivjab nedvce "b, hsb yv vs. pke uedgwgesp ivjab pkes bedutwp pke ceyyhre nt "yjnpuhdpgsr" pke met quvc ehdk dkhuhdpeu vq pke dgwkeupezp pv vnphgs pke vugrgsha ceyyhre.


Enter file name to be decoded with algorithm B: EncB.txt
Decoded message: 
in a symmetric encryption algorithm, both the sender and the recipient use the same key (known as the secret key) to encrypt and decrypt the message. one very basic symmetric encryption algorithm is known as the rotational cipher. in this algorithm, the sender simply "adds" the key to each character of the cleartext message to form the ciphertext. for example, if the key is 2, "a" would become "c", "b" would become "d, and so on. the recipient would then decrypt the message by "subtracting" the key from each character of the ciphertext to obtain the original message.
*/
