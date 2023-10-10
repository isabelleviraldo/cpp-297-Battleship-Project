#include "other.h"

using namespace std;
using namespace call;

int row, col;
tuple<int, int, int> placeShipAuto(int l, gameBoard thisGame);

int main(){
    srand(time(0));
    
    gameBoard thisGame;
    thisGame.createBoard();
    
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
    
    thisGame.playIntro();
    
    bool isHit;
    char rUser;
    char cUser;
    int rowUser;
    int colUser;
    bool pickingSpot;
    int missesTilLoss = 35;
    
    for(int i = 0; i < missesTilLoss; i++){
        isHit = false;
        pickingSpot = true;
        
        if (missesTilLoss - i < 10){
            thisGame.setStats(8, "      Misses Left:  " + to_string(missesTilLoss - i) + "          ||");
        } else {
            thisGame.setStats(8, "      Misses Left: " + to_string(missesTilLoss - i) + "          ||");
        }
        
        thisGame.showBoard();
        
        while(pickingSpot){
            cin >> rUser >> cUser;
            rowUser = (rUser - '0') - 17;
            colUser = (cUser - '0');
            
            if(rowUser >= 0 && rowUser <= ROWS &&
               colUser >= 0 && colUser <= COLS){
                   pickingSpot = false;
            } else { 
                cout << endl; 
                thisGame.setHitStatus(" ||            ERROR: LAUNCH FAILED                                    ||");
                thisGame.showBoard();
            }
        }
        
        for (int j = 0; j < frigate.getLength(); j++){
            if (frigate.shipLocation[j][0] == rowUser && 
                frigate.shipLocation[j][1] == colUser){
                isHit = true;
                frigate.shipLocation[j][0] = -1;
                frigate.shipLocation[j][1] = -1;
                frigate.subHP();
                thisGame.setVisible(rowUser, colUser, "[X]");
                thisGame.setHitStatus(" ||             " + string(1, rUser) + string(1, cUser) + " was a HIT!!!                                        ||");
                if (frigate.getHP() == 0){
                    thisGame.setHitStatus(" ||             YOU SUNK A SHIP!!                                      ||");
                    thisGame.setStats(2, "      Frigate:     SUNK        ||");
                }
                j = 10;
                i--;
            }
        }
        for (int k = 0; k < sub.getLength(); k++){
            if (sub.shipLocation[k][0] == rowUser && 
                sub.shipLocation[k][1] == colUser){
                isHit = true;
                sub.shipLocation[k][0] = -1;
                sub.shipLocation[k][1] = -1;
                sub.subHP();
                thisGame.setVisible(rowUser, colUser, "[X]");
                thisGame.setHitStatus(" ||             " + string(1, rUser) + string(1, cUser) + " was a HIT!!!                                        ||");
                if (sub.getHP() == 0){
                    thisGame.setHitStatus(" ||             YOU SUNK A SHIP!!                                      ||");
                    thisGame.setStats(3, "      Submarine:   SUNK        ||");
                }
                k = 10;
                i--;
            }
        }
        for (int l = 0; l < destroyer.getLength(); l++){
            if (destroyer.shipLocation[l][0] == rowUser && 
                destroyer.shipLocation[l][1] == colUser){
                isHit = true;
                destroyer.shipLocation[l][0] = -1;
                destroyer.shipLocation[l][1] = -1;
                destroyer.subHP();
                thisGame.setVisible(rowUser, colUser, "[X]");
                thisGame.setHitStatus(" ||             " + string(1, rUser) + string(1, cUser) + " was a HIT!!!                                        ||");
                if (destroyer.getHP() == 0){
                    thisGame.setHitStatus(" ||             YOU SUNK A SHIP!!                                      ||");
                    thisGame.setStats(4, "      Destroyer:   SUNK        ||");
                }
                l = 10;
                i--;
            }
        }
        for (int m = 0; m < battleship.getLength(); m++){
            if (battleship.shipLocation[m][0] == rowUser && 
                battleship.shipLocation[m][1] == colUser){
                isHit = true;
                battleship.shipLocation[m][0] = -1;
                battleship.shipLocation[m][1] = -1;
                battleship.subHP();
                thisGame.setVisible(rowUser, colUser, "[X]");
                thisGame.setHitStatus(" ||             " + string(1, rUser) + string(1, cUser) + " was a HIT!!!                                        ||");
                if (battleship.getHP() == 0){
                    thisGame.setHitStatus(" ||             YOU SUNK A SHIP!!                                      ||");
                    thisGame.setStats(5, "      Battleship:  SUNK        ||");
                }
                m = 10;
                i--;
            }
        }
        for (int n = 0; n < aCarrier.getLength(); n++){
            if (aCarrier.shipLocation[n][0] == rowUser && 
                aCarrier.shipLocation[n][1] == colUser){
                isHit = true;
                aCarrier.shipLocation[n][0] = -1;
                aCarrier.shipLocation[n][1] = -1;
                aCarrier.subHP();
                thisGame.setVisible(rowUser, colUser, "[X]");
                thisGame.setHitStatus(" ||             " + string(1, rUser) + string(1, cUser) + " was a HIT!!!                                        ||");
                if (aCarrier.getHP() == 0){
                    thisGame.setHitStatus(" ||             YOU SUNK A SHIP!!                                      ||");
                    thisGame.setStats(6, "      A. Carrier:  SUNK        ||");
                }
                n = 10;
                i--;
            }
        }
        
        if (!isHit){
            thisGame.setHitStatus(" ||             " + string(1, rUser) + string(1, cUser) + " was a miss                                          ||");
            
            if (thisGame.getVisible(rowUser, colUser) != "[X]"){
                thisGame.setVisible(rowUser, colUser, "[O]");
            }
        }
        
        if (frigate.getHP() == 0 &&
        sub.getHP() == 0 &&
        destroyer.getHP() == 0 &&
        battleship.getHP() == 0 &&
        aCarrier.getHP() == 0){
            thisGame.userWon();
            i = 100;
        }   
    }
    
    if (frigate.getHP() == 0 &&
        sub.getHP() == 0 &&
        destroyer.getHP() == 0 &&
        battleship.getHP() == 0 &&
        aCarrier.getHP() == 0 ){
        //do nothing
    } else {
        thisGame.userLost();
    }

    return 0;
}
