//
//  main.cpp
//  Encrypted
//
//  Created by Hellen Pacheco on 3/6/19.
//  Copyright © 2018 Hellen Pacheco. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

#include "CypherA.h"
#include "CypherB.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    const int MAX_TEXT = 1000;
    string filename;
    
    cout << "Enter file name to be decoded with algorithm A: ";
    cin >> filename;
    
    class CypherA messageA (filename, MAX_TEXT);
    
    if (messageA.isEmpty())
    {
        cerr << "ERROR: Message could not be read." << endl;
    }
    else
    {
        messageA.decode();
        cout << "Decoded message: \n";
        messageA.print();
        cout << endl << endl;;
    }
    cout << "Enter file name to be decoded with algorithm B: ";
    cin >> filename;
    
    class CypherB messageB (filename, MAX_TEXT);
    
    if (messageB.isEmpty())
    {
        cerr << "ERROR: Message could not be read." << endl;
    }
    else
    {
        messageB.decode();
        cout << "Decoded message: \n";
        messageB.print();
        cout << endl;
    }
    return 0;
}
