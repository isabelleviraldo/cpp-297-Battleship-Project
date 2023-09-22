#include "other.h"

using namespace std;
using namespace call;

int row, col;

int main(){
    
    //TODO have an intro scene thing for game
    
    gameBoard thisGame;
    thisGame.createBoard();
    
    ship frigate;
    frigate.setShip("Frigate");
    ship sub;
    sub.setShip("Sub");
    ship destroyer;
    destroyer.setShip("Destroyer");
    ship battleship;
    battleship.setShip("Battleship");
    ship aircraftcarrier;
    aircraftcarrier.setShip("Aircraft Carrier");

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
