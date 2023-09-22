#include "other.h"

using namespace std;
using namespace call;

const char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 
                           'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 
                           'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

void gameBoard::createBoard(){
    //sets up visible blank board by filling it with "[ ]"
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
            visibleBoard[r][c] = "[ ]";
        }
    }

    //sets up hidden blank board by filling it with '.'
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
            hiddenBoard[r][c] = '.';
        }
    }

    //TODO generate random ship locations here
    //TODO add ship locations to hidden board here
}

void gameBoard::showBoard(){
    //Show the current state of the board
    cout << "Your Game Board:" << endl;

    for (int c = 0; c < COLS; c++){
        cout << "  " << c;
    }
    cout << "\n";
    
    for (int r = 0; r < ROWS; r++){
        cout << alphabet[r];
        for (int c = 0; c < COLS; c++){
            cout << visibleBoard[r][c];
        }
        cout << endl;
    }

    //TODO
    //print turns left
    //print ships remaining?
}

void gameBoard::setVisible(int r, int c, string newValue){
    visibleBoard[r][c] = newValue;
}

void gameBoard::setHidden(int r, int c, char newValue){
    hiddenBoard[r][c] = newValue;
}
