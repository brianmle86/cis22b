/**
 CIS 22B
 Lab 1: Given an input file of scores, this program
        reads the file, stores all the scores into
        a vector, sorts it in ascending order,
        and calculates the average score as well
        as the median score. It displays the sorted
        vector, average score, and median score for
        the user.
 
 Author: Brian Le
 Date: 01/18/19
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void openFile(ifstream &, string &);
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
    
    printInfo(scores, avg, median);
    
    return 0;
}

/**
 This function attempts to open an input file
 with a default filename(lab1.txt). If it is
 unable to open that file, it prompts the
 user to input a filename until it is able to
 be opened.
 */
void openFile(ifstream &inFile, string &filename) {
    inFile.open(filename);
    while(!inFile) {
        cout << "\nCould not open file.\n"
             << "Please specify a filename: ";
        cin  >> filename;
        inFile.open(filename);
    }
}

/**
 This function reads an input file while scores can
 still be read. The scores are stored inside a vector.
 Once the file is completely read, the input file is closed.
 */
void getScores(ifstream &inFile, vector<int> &vector, int &score) {
    while(inFile >> score) {
        vector.push_back(score);
    }
    inFile.close();
}

/**
 This function sorts a given vector
 into ascending order.
 */
void sortVector(vector<int> &vector) {
    sort(vector.begin(), vector.end());
}

/**
 This function takes a vector and returns
 the average of the values stored inside.
 */
double getAvg(vector<int> &vector) {
    int total = 0;
    double avg;
    for(int score : vector)
        total += score;
    avg = double(total) / vector.size();
    return avg;
}

/**
 This function takes a vector and returns
 the median of the values stored inside.
 */
double getMedian(vector<int> &vector) {
    double median;
    int count = vector.size();
    
    if(count % 2 != 0) //if count is odd
        median = vector[(count / 2) + 1]; //integer division
    else { //if count is even
        int n1, n2;
        n1 = count / 2;
        n2 = n1 + 1;
        median = (vector[n1] + vector[n2]) / 2;
    }
    return median;
}

/**
 This function prints all the values in a vector,
 with 10 values per line, and the average value
 and median value of the values stored inside the vector.
 */
void printInfo(vector<int> &vector, double &avg, double &median) {
    int i = 0; //keeps track of the # of scores on a line
    for(int score : vector) {
        if(i > 9) {
            cout << endl;
            i = 0;
        }
        cout << score << " ";
        i++;
    }
    cout << endl;
    cout << "The average score is " << avg << endl;
    cout << "The median score is " << median << endl;
}

/**
OUTPUT:
60 60 61 62 63 64 64 65 65 67
67 68 68 70 70 71 72 72 72 73
73 74 74 74 74 75 75 76 76 77
77 77 78 78 78 78 78 78 79 79
79 79 80 80 81 81 81 81 81 82
82 82 83 83 83 83 84 84 85 85
85 86 86 87 88 88 88 89 89 90
91 91 91 92 92 92 92 92 93 93
93 93 94 94 94 95 95 95 95 96
96 96 97 97 98 98 99 99 100 100
The average score is 82.2
The median score is 82
*/













