#include <iostream>

using namespace std;

const int ROWS = 10;
const int COLS = 10;

namespace call {
        
    class gameBoard{
        private:
            string visibleBoard[ROWS][COLS];
            char hiddenBoard[ROWS][COLS];
    
        public:
            gameBoard(){}
    
            void createBoard();
    
            void showBoard();
    
            void setVisible(int r, int c, string newValue);
    
            void setHidden(int r, int c, char newValue);
    };

}