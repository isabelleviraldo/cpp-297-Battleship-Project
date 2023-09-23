#include "other.h"

using namespace std;
using namespace call;

//return direction, initial (x, y)
tuple<int, int, int> placeShipAuto(int l, gameBoard thisGame){
    int R = ROWS - 5 + (5 - l);
    int C = COLS - 5 + (5 - l);
    int row;
    int col;
    int direction;
    
    while (true){
        row = (rand() % R);
        col = (rand() % C);
        direction = (rand() % 2);
        cout << row << " " << col << endl;
        
        if (direction == 0){
            //right
            for (int i = 0; i < (l + 1); i++){
                cout << i << endl;
                if (thisGame.getHidden(row, col + i) != '.'){
                    i = (ROWS + COLS);
                    cout << "IN HERE" << endl;
                }
                if (i == l){
                    return {direction, row, col};
                }
            }
        } else {
            //down
            for (int i = 0; i < (l + 1); i++){
                cout << i << endl;
                if (thisGame.getHidden(row + i, col) != '.'){
                    i = (ROWS + COLS);
                    cout << "IN HERE" << endl;
                }
                if (i == l){
                    return {direction, row, col};
                }
            }
        }
    }
};

