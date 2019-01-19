/**
 CIS 22B
 Lab 1: 
 Author: Brian Le
 Date: 01/18/19
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

void openFile(ifstream &, string &);
void closeFile(ifstream &);
void getScores(ifstream &, vector<int> &, int &);
void sortVector(vector<int> &);
double getAvg(vector<int> &);
double getMedian(vector<int> &);
void printInfo(vector<int> &, double &, double &);

int main() {
    ifstream inFile;
    string filename = "lab1.txt";
    vector<int> scores;
    double avg, median;
    int score;

    openFile(inFile, filename);
    
    getScores(inFile, scores, score);

    sortVector(scores);

    avg = getAvg(scores);
    median = getMedian(scores);
    
    closeFile(inFile);
    printInfo(scores, avg, median);
    
    return 0;
}

void openFile(ifstream &inFile, string &filename) {
    inFile.open(filename);
    while(!inFile) {
        cout << "\nCould not open file.\n"
             << "Please specify a filename: ";
        cin  >> filename;
        inFile.open(filename);
    }
}

void closeFile(ifstream &inFile) {
    inFile.close();
}

void getScores(ifstream &inFile, vector<int> &vector, int &score) {
    while(inFile >> score) {
        vector.push_back(score); //create unsorted vector
    }
    inFile.close();
}

void sortVector(vector<int> &vector) {
    sort(vector.begin(), vector.end()); //sort ascending order
}

double getAvg(vector<int> &vector) {
    int total = 0;
    double avg;
    for(int score : vector)
        total += score;
    avg = double(total) / vector.size();
    return avg;
}

double getMedian(vector<int> &vector) {
    double median;
    int count = vector.size();
    
    if(count % 2 != 0)
        median = vector[(count / 2) + 1]; //integer division
    else {
        int n1, n2;
        n1 = count / 2;
        n2 = n1 + 1;
        median = (vector[n1] + vector[n2]) / 2;
    }
    return median;
}

void printInfo(vector<int> &vector, double &avg, double &median) {
    int i = 0;
    for(int score : vector) {
        cout << score << " ";
        if(i > 10) {
            cout << endl;
            i = 0;
        }
        i++;
    }
    cout << endl;
    cout << "The average score is " << avg << endl;
    cout << "The median score is " << median << endl;
}















