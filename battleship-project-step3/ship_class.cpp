#include "other.h"

using namespace std;
using namespace call;

//inputs name of ship
//uses name info to determine symbol to use, length, etc
void ship::setShip(string n){
    name = n;
    
    if (name == "Frigate"){
        symbol = 'F';
        length = 2;
    }else if (name == "Sub"){
        symbol = 'S';
        length = 3;
    }else if (name == "Destroyer"){
        symbol = 'D';
        length = 3;
    }else if (name == "Battleship"){
        symbol = 'B';
        length = 4;
    }else if (name == "Aircraft Carrier"){
        symbol = 'A';
        length = 5;
    }
    
    for (int i = 0; i < length; i++){
        bodyState[i] = symbol;
    }
}

//inputs which part of the ship, and (row,col)
//sets the ship's location as stored in shipLocation to the given (row,col)
void ship::setLocation(int x, int r, int c){
            shipLocation[x][0] = r;
            shipLocation[x][1] = c;
        }

//returns name of ship
string ship::getName(){
    return {name};
}

//returns symbol used on hidden grid
char ship::getSymbol(){
    return {symbol};
}

//returns length of ship
int ship::getLength(){
    return {length};
}

//returns the body of the ship (UNUSED)
//TODO has potential to be referenced when determining if a ship has sunk yet or not if reverted to original '.' state
tuple<char, char, char, char, char> ship::getBodyState(){
    return {bodyState[0], bodyState[1], bodyState[2], bodyState[3], bodyState[4]};
}

//returns the location of the entire ship stored in shipLocation (UNUSED)
tuple<int, int, int, int, int, int, int, int, int, int> ship::getLocation(){
    return {shipLocation[0][0], shipLocation[0][1],
            shipLocation[1][0], shipLocation[1][1],
            shipLocation[2][0], shipLocation[2][1],
            shipLocation[3][0], shipLocation[3][1],
            shipLocation[4][0], shipLocation[4][1]};
}
