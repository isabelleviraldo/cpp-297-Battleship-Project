#include <iostream>
#include <string>
#include <tuple>
using namespace std;

const int ROWS = 10;
const int COLS = 10;
const char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 
                           'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 
                           'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

class gameBoard{
    private:
        string visibleBoard[ROWS][COLS];
        char hiddenBoard[ROWS][COLS];
    public:
        gameBoard(){}

        void createBoard(){
            //sets up visible blank board by filling it with "[ ]"
            for (int r = 0; r < ROWS; r++){
                for (int c = 0; c < COLS; c++){
                    visibleBoard[r][c] = "[ ]";
                }
            }

            //sets up hidden blank board by filling it with "[ ]"
            for (int r = 0; r < ROWS; r++){
                for (int c = 0; c < COLS; c++){
                    hiddenBoard[r][c] = '.';
                }
            }

            //TODO generate random ship locations here

            //TODO add ship locations to hidden board here

        }

        void showBoard(){
            //Show the current state of the board
            for (int c = 0; c < COLS; c++){
                cout << "  " << c;
            }
            cout << "\n";
            
            for (int r = 0; r < ROWS; r++){
                cout << alphabet[r];
                for (int c = 0; c < COLS; c++){
                    cout << visibleBoard[r][c];
                }
                cout << endl;
            }

            /*
            int row, col;

            // how it shows one of the options

            row = currentRow - 2; col = currentCol + 1;
            if (row >=0 && row < ROWS && col >=0 && col < COLS)
            {
                cout << "board[" << row << "][" << col << "] or \n";
                board[row][col] = "[L]";
            }
            */
        }

        void setVisible(int r, int c, string newValue){
            visibleBoard[r][c] = newValue;
        }

        void setHidden(int r, int c, char newValue){
            hiddenBoard[r][c] = newValue;
        }



        
};

tuple<string, char> takeTurn(int currentRow, int currentCol){
    string visible;
    char hidden;

    /*TODO check hidden board (row, col) to see stats
    if . {
        visible = "[O]";
        hidden = '0';
    } else {
        visible = "[X]";
        if (certain ship) {
            hidden = '1' ;
            adjust ship data
            if (ship 100% hit){
                        cout << shiptype << "has been sunk" << endl;
            }
        }
    }
    */
    
    cout << "Your current position on the board is [" << currentCol << "][" << currentRow << "] \n";
    visible = "[X]";
    hidden = '1';
    return {visible, hidden};
}

int main(){
    
    gameBoard thisGame;
    thisGame.createBoard();

    int row, col;

    for(int i = 0; i < 3; i++){
        cout << "Your current position on the board (input first column, then row): ";
        cin >> col >> row;
        auto [vis, hid] = takeTurn(row, col);
        thisGame.setVisible(row, col, vis);
        thisGame.setHidden(row, col, hid);
        thisGame.showBoard();
    }

    return 0;
}
