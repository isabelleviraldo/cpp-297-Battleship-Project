#include "other.h"

using namespace std;
using namespace call;

//inputs length of the ship im working with, as well as the class gameBoard im using (it has my grid info)
//returns direction, and initial (row, col)
tuple<int, int, int> placeShipAuto(int len, gameBoard thisGame){
    //make sure that it wont go out of bounds of grid
    int R = ROWS - len;
    int C = COLS - len;
    
    int row;
    int col;
    int direction;
    
    //loops until a direction with (row, col) is found that doesnt hit anything
    while (true){
        //get random direction and location
        direction = (rand() % 2);
        row = (rand() % R);
        col = (rand() % C);
        
        if (direction == 0){
            //right
            for (int i = 0; i < (len + 1); i++){
                //if location at point ISNT water, exit for loop to get new point
                if (thisGame.getHidden(row, col + i) != '.' /*||
                    thisGame.getHidden(row, col + i) != 'O'*/){
                    i = (ROWS + COLS); 
                }
                //if everything is clear, this direction and (row, col) is good to use
                if (i == len){
                    return {direction, row, col};
                }
            }
        } else {
            //down
            for (int i = 0; i < (len + 1); i++){
                //if location at point ISNT water, exit for loop to get new point
                if (thisGame.getHidden(row + i, col) != '.' ||
                    thisGame.getHidden(row + i, col) != 'O'){
                    i = (ROWS + COLS);
                }
                //if everything is clear, this direction and (row, col) is good to use
                if (i == len){
                    return {direction, row, col};
                }
            }
        }
    }
};
