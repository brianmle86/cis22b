/**
 CIS22B
 Lab 2:

Author: Brian Le
Date: 02/01/19
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_STUDENTS = 50;

int main() {
    ifstream inFile;
    string filename = "lab2.txt";
    int name;
    string score;

    struct Student {
        string name;
        int score;
    };
    
    vector<string> names;
    vector<int> scores;   
    vector<int> finalScores;
    vector<Student> students = MAX_STUDENTS;

}

void openFile(ifstream &inFile, string &filename) {
    inFile.open(filename);
    while(!inFile) {
        cout << "\nCould not open file.\n"
             << "Please specify file name: ";
        cin  >> filename;
        inFile.open(filename);
    }
}
void getScores(ifstream &inFile, vector<int> &vector1, vector<int> &vector2, vector<string> &namevector, string &name, int &score) {
    while(inFile >> name) {
        namevector.push_back(name);
        for(int i = 0; i < 10; i++) {
            inFile >> score;
            vector1.push_back(score);
            double avg = getAvg(vector1);
            vector2.push_back(avg);
        }
    }
}

void getStructs(vector<string> &namevector, vector<int> &scorevector, vector<Student> &students) {
    //Student student;
    int num = namevector.size();
    for(int i = 0; i < num; i++) {
                
    }
}



double getAvg(vector<int> &vector) {
    int total = 0;
    double avg;
    for(int score : vector)
        total += score;
    avg = double(total) / vector.size();
    return avg;
}
