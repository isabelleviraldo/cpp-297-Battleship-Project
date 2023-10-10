#include "other.h"

using namespace std;
using namespace call;

//saved for increasing board size if adding the size adjustment feature
const char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 
                           'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 
                           'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

//this creates the board, visual one, and the hidden one
void gameBoard::createBoard(){
    //sets up visible blank board by filling it with "[ ]"
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
            visibleBoard[r][c] = "[ ]";
        }
    }

    //sets up hidden blank board by filling it with '.'
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
            hiddenBoard[r][c] = '.';
        }
    }

    //TODO generate random ship locations here
    //TODO add ship locations to hidden board here
}

void gameBoard::playIntro(){
    
    cout << " ------------------------------------------------------------------------" << endl;
    cout << " ||--------------------------------------------------------------------||" << endl;
    cout << " ||            ____        _   _   _           _     _                 ||" << endl;
    cout << " ||           |  _ \\      | | | | | |         | |   (_)                ||" << endl;
    cout << " ||           | |_) | __ _| |_| |_| | ___  ___| |__  _ _ __            ||" << endl;
    cout << " ||           |  _ < / _` | __| __| |/ _ \\/ __| '_ \\| | '_ \\           ||" << endl;
    cout << " ||           | |_) | (_| | |_| |_| |  __/\\__ \\ | | | | |_) |          ||" << endl;
    cout << " ||           |____/ \\__,_|\\__|\\__|_|\\___||___/_| |_|_| .__/           ||" << endl;
    cout << " ||     ----------------------------------------------| |---------     ||" << endl;
    cout << " ||         (created by Isabelle Viraldo)             |_|              ||" << endl;
    cout << " ||                                                                    ||" << endl;
    cout << " ||                                  # #   ( )                         ||" << endl;
    cout << " ||                                ___#_#___|__                        ||" << endl;
    cout << " ||                            _  |____________|  _                    ||" << endl;
    cout << " ||                     _=====| | |            | | |==== _             ||" << endl;
    cout << " ||               =====| |.---------------------------. | |====        ||" << endl;
    cout << " ||  <------------------'   .  .  .  .  .  .  .  .   '-------------/   ||" << endl;
    cout << " ||    \\                                                          /    ||" << endl;
    cout << " ||     \\_____________________________________________<;>________/     ||" << endl;
    cout << " ||                                                                    ||" << endl;
    cout << " ||                                                                    ||" << endl;
    cout << " ||      Commander! We need you! You're our only hope!                 ||" << endl;
    cout << " ||      Can you help us in our hour of need?                          ||" << endl;
    cout << " ||                                                                    ||" << endl;
    cout << " ||      Press ENTER to start the game                                 ||" << endl;
    cout << " ||                                                                    ||" << endl;
    cout << " ||--------------------------------------------------------------------||" << endl;
    cout << " ------------------------------------------------------------------------" << endl;
    cin.get();
}

//shows the user the current state of the board
void gameBoard::showBoard(){
    cout << " ------------------------------------------------------------------------" << endl;
    cout << " ||--------------------------------------------------------------------||" << endl;
    cout << " ||            ____        _   _   _           _     _                 ||" << endl;
    cout << " ||           |  _ \\      | | | | | |         | |   (_)                ||" << endl;
    cout << " ||           | |_) | __ _| |_| |_| | ___  ___| |__  _ _ __            ||" << endl;
    cout << " ||           |  _ < / _` | __| __| |/ _ \\/ __| '_ \\| | '_ \\           ||" << endl;
    cout << " ||           | |_) | (_| | |_| |_| |  __/\\__ \\ | | | | |_) |          ||" << endl;
    cout << " ||           |____/ \\__,_|\\__|\\__|_|\\___||___/_| |_|_| .__/           ||" << endl;
    cout << " ||     ----------------------------------------------| |---------     ||" << endl;
    cout << " ||                                                   |_|              ||" << endl;
    cout << hitStatus << endl;
    cout << " ||                                                                    ||" << endl;
    
    
    cout << " ||      ";

    for (int c = 0; c < COLS; c++){
        cout << "  " << c;
        
    }
    cout << "                                || ";
    cout << "\n";
    
    for (int r = 0; r < ROWS; r++){
        cout << " ||      ";
        cout << alphabet[r];
        for (int c = 0; c < COLS; c++){
            cout << visibleBoard[r][c];
        }
        cout << statsString[r];
        cout << endl;
    }

    cout << " ||                                                                    ||" << endl;
    cout << " ||                                                                    ||" << endl;
    cout << " ||--------------------------------------------------------------------||" << endl;
    cout << " ------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "       Where will you hit next? (ie F4)  ";
}

void gameBoard::userWon(){
    cout << " ------------------------------------------------------------------------" << endl;
    cout << " ||--------------------------------------------------------------------||" << endl;
    cout << " ||          __     __                               _ _ _             ||" << endl;
    cout << " ||          \\ \\   / /                              | | | |            ||" << endl;
    cout << " ||           \\ \\_/ /__  _   _  __      _ ___  _ __ | | | |            ||" << endl;
    cout << " ||            \\   / _ \\| | | | \\ \\ /\\ / / _ \\| '_ \\| | | |            ||" << endl;
    cout << " ||             | | (_) | |_| |  \\ V  V / (_) | | | |_|_|_|            ||" << endl;
    cout << " ||             |_|\\___/ \\__,_|   \\_/\\_/ \\___/|_| |_(_|_|_)            ||" << endl;
    cout << " ||       ------------------------------------------------------       ||" << endl;
    cout << " ||                                                                    ||" << endl;
    cout << " ||       Thanks to your wit and bravery you lead our fleet to         ||" << endl;
    cout << " ||       victory against the enemy, it is an honor to serve with      ||" << endl;
    cout << " ||       you, and we hope you will lead us again another day!         ||" << endl;
    cout << " ||                                                                    ||" << endl;
    
    cout << " ||                   ";

    for (int c = 0; c < COLS; c++){
        cout << "  " << c;
        
    }
    cout << "                   || ";
    cout << "\n";
    
    for (int r = 0; r < ROWS; r++){
        cout << " ||                  ";
        cout << alphabet[r] << " ";
        for (int c = 0; c < COLS; c++){
            cout << " " << hiddenBoard[r][c] << " ";
        }
        cout << "                  ||";
        cout << endl;
    }
    
    cout << " ||                                                                    ||" << endl;
    cout << " ||--------------------------------------------------------------------||" << endl;
    cout << " ------------------------------------------------------------------------" << endl;
}

void gameBoard::userLost(){
    cout << " ------------------------------------------------------------------------" << endl;
    cout << " ||--------------------------------------------------------------------||" << endl;
    cout << " ||             __     __            _                                 ||" << endl;
    cout << " ||             \\ \\   / /           | |                                ||" << endl;
    cout << " ||              \\ \\_/ /__  _   _   | |     ___  ___  ___              ||" << endl;
    cout << " ||               \\   / _ \\| | | |  | |    / _ \\/ __|/ _ \\             ||" << endl;
    cout << " ||                | | (_) | |_| |  | |___| (_) \\__ \\  __/             ||" << endl;
    cout << " ||                |_|\\___/ \\__,_|  |______\\___/|___/\\___|             ||" << endl;
    cout << " ||       ------------------------------------------------------       ||" << endl;
    cout << " ||                                                                    ||" << endl;
    cout << " ||        You're the best we got Commander, you can pull this         ||" << endl;
    cout << " ||        off! Give it another go, and then together, we can          ||" << endl;
    cout << " ||        defeat the enemy! We hope to serve with you again!          ||" << endl;
    cout << " ||                                                                    ||" << endl;
    
    cout << " ||                   ";

    for (int c = 0; c < COLS; c++){
        cout << "  " << c;
        
    }
    cout << "                   || ";
    cout << "\n";
    
    for (int r = 0; r < ROWS; r++){
        cout << " ||                  ";
        cout << alphabet[r] << " ";
        for (int c = 0; c < COLS; c++){
            cout << " " << hiddenBoard[r][c] << " ";
        }
        cout << "                  ||";
        cout << endl;
    }
    
    cout << " ||                                                                    ||" << endl;
    cout << " ||--------------------------------------------------------------------||" << endl;
    cout << " ------------------------------------------------------------------------" << endl;
}


//just to show what im referencing for the code, has ship locations, so is useful for testing
void gameBoard::showHBoard(){
    //Show the current state of the board
    cout << "Your Game Board:" << endl;

    for (int c = 0; c < COLS; c++){
        cout << "  " << c;
    }
    cout << "\n";
    
    for (int r = 0; r < ROWS; r++){
        cout << alphabet[r];
        for (int c = 0; c < COLS; c++){
            cout << " " << hiddenBoard[r][c] << " ";
        }
        cout << endl;
    }
    
    //TODO
    //should porobably print all of the relavent info I can think of would be
    
}

//returns value at point on visible grid
//unused because it would return something like '[ ]', and the hidden grid is more useful
string gameBoard::getVisible(int r, int c){
    return visibleBoard[r][c];
}

//returns value at point on hidden grid
char gameBoard::getHidden(int r, int c){
    return hiddenBoard[r][c];
}

//set a value to a new one at a certain point
void gameBoard::setVisible(int r, int c, string newValue){
    visibleBoard[r][c] = newValue;
}

void gameBoard::setStats(int r, string newValue){
    statsString[r] = newValue;
}

//set a value to a new one at a certain point
void gameBoard::setHidden(int r, int c, char newValue){
    hiddenBoard[r][c] = newValue;
}

void gameBoard::setHitStatus(string newValue){
    hitStatus = newValue;
}
