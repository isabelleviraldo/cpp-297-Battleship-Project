#include <iostream>
#include <tuple>
#include <cstring>
#include <cstdlib>
#include <time.h>

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

using namespace std;

const int ROWS = 10;
const int COLS = 10;

//initialising functions
tuple<string, char> checkSuccess(int currentRow, int currentCol);

//initialising classes
namespace call {
    class gameBoard{
        private:
            string visibleBoard[ROWS][COLS];
            char hiddenBoard[ROWS][COLS];
            
        public:
            gameBoard(){};
            void createBoard();
            void showBoard();
            void showHBoard();
            string getVisible(int r, int c);
            char getHidden(int r, int c);
            void setVisible(int r, int c, string newValue);
            void setHidden(int r, int c, char newValue);
    };
    
    class ship{
        private:
            string name;
            char symbol;
            int length;
            char bodyState[5] = {'.', '.', '.', '.', '.'};
            int shipLocation[5][2] = {{-1, -1}, 
                                      {-1, -1},
                                      {-1, -1}, 
                                      {-1, -1},
                                      {-1, -1}};
            
        public:
            ship(){};
            void setShip(string n);
            void setLocation(int x, int r, int c);
            string getName();
            char getSymbol();
            int getLength();
            tuple<char, char, char, char, char> getBodyState();
            tuple<int, int, int, int, int, int, int, int, int, int> getLocation();
    };
}

#endif
