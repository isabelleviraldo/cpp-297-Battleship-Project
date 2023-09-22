#include "other.h"

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