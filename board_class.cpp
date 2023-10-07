#include "other.h"

using namespace std;
using namespace call;

//saved for increasing board size if adding the size adjustment feature
const char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 
                           'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 
                           'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

//this creates the board, visual one, and the hidden one
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

//shows the user the current state of the board
void gameBoard::showBoard(){
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

//just to show what im referencing for the code, has ship locations, so is useful for testing
void gameBoard::showHBoard(){
    //Show the current state of the board
    cout << "Your Game Board:" << endl;

    for (int c = 0; c < COLS; c++){
        cout << "  " << c;
    }
    cout << "\n";
    
    for (int r = 0; r < ROWS; r++){
        cout << alphabet[r];
        for (int c = 0; c < COLS; c++){
            cout << " " << hiddenBoard[r][c] << " ";
        }
        cout << endl;
    }
    
    //TODO
    //should porobably print all of the relavent info I can think of would be
    
}

//returns value at point on visible grid (UNUSED)
//unused because it would return something like '[ ]', and the hidden grid is more useful
string gameBoard::getVisible(int r, int c){
    return visibleBoard[r][c];
}

//returns value at point on hidden grid
char gameBoard::getHidden(int r, int c){
    return hiddenBoard[r][c];
}

//set a value to a new one at a certain point
void gameBoard::setVisible(int r, int c, string newValue){
    visibleBoard[r][c] = newValue;
}

//set a value to a new one at a certain point
void gameBoard::setHidden(int r, int c, char newValue){
    hiddenBoard[r][c] = newValue;
}
