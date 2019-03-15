/**
 CIS22B
 Brian Le

 Contains function definitions for CypherB.
 */
#include "CypherB.h"
#include <string>

using namespace std;

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
