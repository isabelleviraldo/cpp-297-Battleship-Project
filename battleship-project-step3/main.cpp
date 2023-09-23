#include "other.h"

using namespace std;
using namespace call;

int row, col;
tuple<int, int, int> placeShipAuto(int l, gameBoard thisGame);

int main(){
    srand(time(0));
    
    //TODO have an intro scene thing for game
    
    gameBoard thisGame;
    thisGame.createBoard();
    
    
    //TODO move all the ships being initialised to the board class, so the board info is easy to access and you can access the ship info from the same place
    
    //initialises ship
    ship frigate;
    frigate.setShip("Frigate");
    
    //gets direction and start location that is clear
    auto [frigatedir, frigateplaceROW, frigateplaceCOL] = placeShipAuto(frigate.getLength(), thisGame);
    
    //depending on direction, go that ships length
    for (int i = 0; i < frigate.getLength(); i++){
        if (frigatedir == 0){
            //right
            //place marker within ship's class
            frigate.setLocation(i, frigateplaceROW, frigateplaceCOL + i);
            //place marker within hidden grid
            thisGame.setHidden(frigateplaceROW, frigateplaceCOL + i, frigate.getSymbol());
        } else if (frigatedir == 1){
            //down
            //place marker within ship's class
            frigate.setLocation(i, frigateplaceROW + i, frigateplaceCOL);
            //place marker within hidden grid
            thisGame.setHidden(frigateplaceROW + i, frigateplaceCOL, frigate.getSymbol());
        }
    }
    
    ship sub;
    sub.setShip("Sub");
    auto [subdir, subplaceROW, subplaceCOL] = placeShipAuto(sub.getLength(), thisGame);
    for (int i = 0; i < sub.getLength(); i++){
        if (subdir == 0){
            sub.setLocation(i, subplaceROW, subplaceCOL + i);
            thisGame.setHidden(subplaceROW, subplaceCOL + i, sub.getSymbol());
        } else if (subdir == 1){
            sub.setLocation(i, subplaceROW + i, subplaceCOL);
            thisGame.setHidden(subplaceROW + i, subplaceCOL, sub.getSymbol());
        }
    }
    
    ship destroyer;
    destroyer.setShip("Destroyer");
    auto [destroyerdir, destroyerplaceROW, destroyerplaceCOL] = placeShipAuto(destroyer.getLength(), thisGame);
    for (int i = 0; i < destroyer.getLength(); i++){
        if (destroyerdir == 0){
            destroyer.setLocation(i, destroyerplaceROW, destroyerplaceCOL + i);
            thisGame.setHidden(destroyerplaceROW, destroyerplaceCOL + i, destroyer.getSymbol());
        } else if (destroyerdir == 1){
            destroyer.setLocation(i, destroyerplaceROW + i, destroyerplaceCOL);
            thisGame.setHidden(destroyerplaceROW + i, destroyerplaceCOL, destroyer.getSymbol());
        }
    }
    
    ship battleship;
    battleship.setShip("Battleship");
    auto [battleshipdir, battleshipplaceROW, battleshipplaceCOL] = placeShipAuto(battleship.getLength(), thisGame);
    for (int i = 0; i < battleship.getLength(); i++){
        if (battleshipdir == 0){
            battleship.setLocation(i, battleshipplaceROW, battleshipplaceCOL + i);
            thisGame.setHidden(battleshipplaceROW, battleshipplaceCOL + i, battleship.getSymbol());
        } else if (battleshipdir == 1){
            battleship.setLocation(i, battleshipplaceROW + i, battleshipplaceCOL);
            thisGame.setHidden(battleshipplaceROW + i, battleshipplaceCOL, battleship.getSymbol());
        }
    }
    
    ship aCarrier;
    aCarrier.setShip("Aircraft Carrier");
    auto [aCarrierdir, aCarrierplaceROW, aCarrierplaceCOL] = placeShipAuto(aCarrier.getLength(), thisGame);
    for (int i = 0; i < aCarrier.getLength(); i++){
        if (aCarrierdir == 0){
            aCarrier.setLocation(i, aCarrierplaceROW, aCarrierplaceCOL + i);
            thisGame.setHidden(aCarrierplaceROW, aCarrierplaceCOL + i, aCarrier.getSymbol());
        } else if (aCarrierdir == 1){
            aCarrier.setLocation(i, aCarrierplaceROW + i, aCarrierplaceCOL);
            thisGame.setHidden(aCarrierplaceROW + i, aCarrierplaceCOL, aCarrier.getSymbol());
        }
    }
    
    //prints out the hidden board with ship info
    thisGame.showHBoard();
    
    /*for(int i = 0; i < 7; i++){
        cout << "Your current position on the board (input first column, then row): ";
        cin >> col >> row;
        auto [vis, hid] = checkSuccess(row, col);
        thisGame.setVisible(row, col, vis);
        thisGame.setHidden(row, col, hid);
        thisGame.showBoard();
    }*/

    return 0;
}
