#include <Encrypted.h>
#include <fstream>

Encrypted(string filename, int max) {
    ifstream inFile;
    inFile.open(filename);
    if(!inFile) {
        cout << "could not open file\n";
        exit(1);
    }
    char *message = new char[max];
}
