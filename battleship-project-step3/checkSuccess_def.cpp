#include "other.h"

using namespace std;
using namespace call;

//inputs the coords the user inputs
//outputs the result of the launch ([X] or [O]) and what to set the hidden grid to do
//TODO honestly should change this to just a bool, true/false (hit/miss)
tuple<string, char> checkSuccess(int userRow, int userCol){
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
    cout << "Your current position on the board is [" << userCol << "][" << userRow << "] \n";
    visible = "[X]";
    hidden = '1';

    return {visible, hidden};
}
