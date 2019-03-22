/**
 CIS22B
 Brian Le

 This file contains the Player class.
 */
#include "LoShuSquare.h"
#include <string>
#include <iostream>

#ifndef Player_h
#define Player_h

using namespace std;

class Player {
    private:
        LoShuSquare game;
    public:
        Player(LoShuSquare game);
        ~Player();
};

Player::Player(LoShuSquare game) {
    int row, column, value;
    char input;
    cout << "A Lo Shu Square is a 3x3 grid which\n"
         << "consists of numbers 1 - 9. All rows, columns,\n"
         << "and diagonals must add up to 15.\n\n";

    cout << "Here is an empty grid.\n";
    game.printGrid();

    cout << "Please fill out the values of the grid:\n";
    int number;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << "Enter value of row " << (i + 1)
                 << ", column " << (j + 1) << ": ";
            cin >> number;
            game.fill(i, j, number);
            cout << endl;
            game.printGrid();
        }
    }
    cout << "=============================================\n";
   
    game.printGrid();
    cout << "Would you like to change a specific value\n"
         << "in the grid? (y/n): ";
    cin >> input;
    while(input == 'Y' || input == 'y') {
        cout << "Enter row, column, and value: ";
        cin >> row >> column >> value;
        row -= 1; //we need the index, so - 1
        column -= 1;
        game.fill(row, column, value);
        cout << endl;
        game.printGrid();
        
        cout << "Change another value? (y/n): ";
        cin >> input;
    }

    bool isLoShuSquare = game.isLoShuSquare();
    if(isLoShuSquare) {
        cout << "The grid is a Lo Shu Square.\n";
    }
    else {
        cout << "The grid is not a Lo Shu Square.\n";
    }

}
Player::~Player() {};
#endif
