#include "other.h"

#include <iostream>
#include <string>
#include <tuple>

using namespace std;
using namespace call;

tuple<string, char> checkSuccess(int currentRow, int currentCol){
    string visible;
    char hidden;

    /*TODO check hidden board (row, col) to see stats
    if . {
        visible = "[O]";
        hidden = '0';
    } else {
        visible = "[X]";
        if (certain ship) {
            hidden = '1' ;
            adjust ship data
            if (ship 100% hit){
                cout << shiptype << "has been sunk" << endl;
            }
        }
    }
    */
    
    //temp setup rn before entering ship data
    cout << "Your current position on the board is [" << currentCol << "][" << currentRow << "] \n";
    visible = "[X]";
    hidden = '1';

    return {visible, hidden};
}

int main(){
    
    gameBoard thisGame;
    thisGame.createBoard();

    int row, col;

    for(int i = 0; i < 7; i++){
        cout << "Your current position on the board (input first column, then row): ";
        cin >> col >> row;
        auto [vis, hid] = checkSuccess(row, col);
        thisGame.setVisible(row, col, vis);
        thisGame.setHidden(row, col, hid);
        thisGame.showBoard();
    }

    return 0;
}
