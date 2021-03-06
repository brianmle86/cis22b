/**
 CIS22B
 Brian Le

 This file contains the LoShuSquare class.
 */
#ifndef LoShuSquare_h
#define LoShuSquare_h
#include <iostream>
using namespace std;

class LoShuSquare {
    private:
        int magicSum = 15; //sum must be 15, so we call this magic sum
        int grid[3][3];
    public:
        LoShuSquare();
        ~LoShuSquare();
        void fill(int row, int col, int num);
        bool checkRow(int array[][3]); //all the "check" functions return true        
        bool checkCol(int array[][3]); //if ALL of the rows, columns, or diagonals add up to 15.
        bool checkDiag(int array[][3]);
        bool isLoShuSquare();
        void printGrid();
};

LoShuSquare::LoShuSquare() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++)
            grid[i][j] = 0;
    }
}

LoShuSquare::~LoShuSquare() {};

inline void LoShuSquare::fill(int row, int col, int num) {
    grid[row][col] = num;
}

inline bool LoShuSquare::checkRow(int array[][3]) {
    int sum = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++)
            sum += array[i][j];
        
        if(sum != magicSum)
            return false; //if one row is not 15, returns false
        else
            sum = 0;
    } 
    return true; //all rows sum to 15, so return true
}

inline bool LoShuSquare::checkCol(int array[][3]) {
    int sum = 0;
    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < 3; i++)
            sum += array[i][j];
        
        if(sum != magicSum)
            return false;
        else
            sum = 0;
    }
    return true;
}

inline bool LoShuSquare::checkDiag(int array[][3]) {
    int sum = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == j)
                sum += array[i][j];
        }
    }
    
    if(sum != magicSum)
        return false;
    else
        sum = 0;
    
    sum = array[0][2] + array[1][1] + array[2][0];
    if(sum != magicSum) //check other "cross"
        return false;
    else
        return true;
}

inline bool LoShuSquare::isLoShuSquare() {
    if(checkRow(grid) && checkCol(grid) && checkDiag(grid))
        return true;
    else
        return false;
}

inline void LoShuSquare::printGrid() {
    cout << "---------";
    for(int i = 0; i < 3; i++) {
        cout << endl << "| ";
        for(int j = 0; j < 3; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "|";
    }
    cout << endl << "---------\n";
}

#endif
