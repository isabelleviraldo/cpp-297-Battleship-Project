#include "other.h"

using namespace std;
using namespace call;

void ship::setShip(string n){
    name = n;
    
    if (strcmp(name, "Frigate") == 0){
        symbol = 'F';
        length = 2;
    }else if (strcmp(name, "Sub") == 0){
        symbol = 'S';
        length = 3;
    }else if (strcmp(name, "Destroyer") == 0){
        symbol = 'D';
        length = 3;
    }else if (strcmp(name, "Battleship") == 0){
        symbol = 'B';
        length = 4;
    }else if (strcmp(name, "Aircraft Carrier") == 0){
        symbol = 'A';
        length = 5;
    }
    
    for (i = 0; i < length; i++){
        bodyState[i] = symbol;
    }
}
        
void ship::setLocation(int x, int r, int c){
            shipLocation[x][0] = r;
            shipLocation[x][1] = c;
        }
        
string ship::getName(){
    return {name};
}
        
string ship::getSymbol(){
    return {symbol};
}
        
string ship::getLength(){
    return {length};
}
        
tuple<char, char, char, char, char> ship::getBodyState(){
    return {bodyState[0], bodyState[1], bodyState[2]], bodyState[3], bodyState[4]};
}
        
tuple<int, int, int, int, int, int, int, int, int, int> ship::getLocation(){
    return {shipLocation[0][0], shipLocation[0][1],
            shipLocation[1][0], shipLocation[1][1],
            shipLocation[2][0], shipLocation[2][1],
            shipLocation[3][0], shipLocation[3][1],
            shipLocation[4][0], shipLocation[4][1]};
}
