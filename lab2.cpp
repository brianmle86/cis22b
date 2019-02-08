/**
 CIS22B
 Lab 2: Given an input file of student names and test scores,
        this program calculates each student's final test score,
        and stores the students' names and test scores in a vector
        of structures. The program then sorts the vector of structures
        by name or by score and displays them. A class average and 
        median is then calculated and displayed.

Author: Brian Le
Date(due): 02/01/19
Date(completed): 02/07/19
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
struct Student {
    string name;
    int score;
};

void openFile(ifstream &, string &);
void getScores(ifstream &, vector<int> &, vector<int> &, vector<string> &, string &, int &);
void getStructs(vector<string> &, vector<int> &, vector<Student> &);
double getAvg(vector<int> &);
bool compareByName(Student, Student);
bool compareByScore(Student, Student); 
void displayStruct(vector<Student> &);
void printInfo(vector<Student> &, vector<int> &);

int main() {
    ifstream inFile;
    string filename = "lab2.txt";
    string name;
    int score;

    
    vector<string> names;
    vector<int> scores;   
    vector<int> finalScores;
    vector<Student> students;
    
    openFile(inFile, filename);
    getScores(inFile, scores, finalScores, names, name, score);
    getStructs(names, finalScores, students);
    printInfo(students, finalScores);
    return 0;
}

/**
 This function attempts to open an input file with
 default name "lab2.txt". If it is unable to, the function
 prompts the user to specify a filename.
  */
void openFile(ifstream &inFile, string &filename) {
    inFile.open(filename);
    while(!inFile) {
        cout << "\nCould not open file.\n"
             << "Please specify file name: ";
        cin  >> filename;
        inFile.open(filename);
    }
}

/**
 This function reads the input file, and stores the contents
 into vectors based on the data. Names are stored into
 their own vectors first. Then, the function takes the next
 10 scores and averages them, storing the average score into
 a vector of final scores. This results in parallel vectors.
 */
void getScores(ifstream &inFile, vector<int> &vector1, vector<int> &vector2, vector<string> &namevector, string &name, int &score) {
    while(inFile >> name) {
        namevector.push_back(name);
        for(int i = 0; i < 10; i++) {
            inFile >> score;
            vector1.push_back(score);
        }
            double avg = getAvg(vector1);
            vector2.push_back(avg);
        vector1.clear();
    }
    inFile.close();
}
/**
 This function takes the two parallel vectors
 of names and final scores and creates a vector of structures.
 The structure is Student, which holds a name and final score.
 */
void getStructs(vector<string> &namevector, vector<int> &scorevector, vector<Student> &students) {
    Student student;
    int num = namevector.size();
    for(int i = 0; i < num; i++) {
        students.push_back({namevector[i], scorevector[i]});               
    }
}
/**
 This function takes a vector of structures and displays
 the name and final score for each student.
 */
void displayStruct(vector<Student> &students) {
    cout << "=======================================\n";
    for(Student student : students)
        cout << student.name << " " << student.score << endl;
    cout << "=======================================\n\n";

}

/**
 This function takes a vector of ints
 and calculates the average.
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
 Allows the sort function to sort by name
 in ascending order.
 */
bool compareByName(Student stu1, Student stu2) {
    return(stu1.name < stu2.name);
}

/**
 Allows the sort function to sort by score
 in ascending order.
 */
bool compareByScore(Student stu1, Student stu2) {
    return(stu1.score < stu2.score);
}

/**
 This function takes a vector and returns
  the median of the values stored inside.
 */
double getMedian(vector<int> &vector) {
    double median;
    int count = vector.size();
     
    if(count % 2 != 0) //if count is odd
        median = vector[(count / 2)]; //integer division
    else { //if count is even
        int n1, n2;
        n1 = (count / 2) - 1;
        n2 = n1 + 1;
        median = (vector[n1] + vector[n2]) / 2.0;
    }
    return median;
}
/**
 This function sorts the vector of stuctures by name and then
 calls displayStruct to display the vector.(Same for score).
 it then displays a class average and a class median. Note that
 the function sorts the finalScores vector before calling getMedian.
 */
void printInfo(vector<Student> &students, vector<int> &finalScores) {
    sort(students.begin(), students.end(), compareByName);
    cout << "Students sorted by name:\n";
    displayStruct(students);

    sort(students.begin(), students.end(), compareByScore);
    cout << "Students sorted by score:\n";
    displayStruct(students);
    
    double classavg = getAvg(finalScores);
    cout << "Class average: " << classavg << endl;
    sort(finalScores.begin(), finalScores.end());
    int classmed = getMedian(finalScores);
    cout << "Class median: " << classmed << endl;
}

/**
OUTPUT:
Students sorted by name:
=======================================
Anna 73
Daniel 66
Helena 93
Jason 91
Kim 84
Lawrence 71
Maria 95
Max 81
Peter 82
Tricia 86
=======================================

Students sorted by score:
=======================================
Daniel 66
Lawrence 71
Anna 73
Max 81
Peter 82
Kim 84
Tricia 86
Jason 91
Helena 93
Maria 95
=======================================

Class average: 82.2
Class median: 83
*/
