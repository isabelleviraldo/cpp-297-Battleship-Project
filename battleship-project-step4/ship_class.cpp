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
    
    hp = length;
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

//returns the hp left
int ship::getHP(){
    return {hp};
}

void ship::subHP(){
    hp--;
}
