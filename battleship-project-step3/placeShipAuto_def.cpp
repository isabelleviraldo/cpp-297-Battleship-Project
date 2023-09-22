#include "other.h"

using namespace std;
using namespace call;

//return direction, initial (x, y)
tuple<int, int, int> placeShipAuto(int l){
    bool found = false;
    int R = ROWS - (5 - l);
    int C = COLS - (5 - l);
    
    while (!found){
        int row = (rand() % ROWS);
        int col = (rand() % COLS);
        int direction = (rand() % 2);
        
        if (direction == 0){
            //right
            
            
        } else {
            //down
        }
    }
    
    return {direction, row, col};
    
};