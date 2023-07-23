//
//  Game.hpp
//  tic-tac-toe
//
//  Created by Austin on 1/8/21.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "GamePiece.hpp"
#include "Board.hpp"

class Game {
private:
    Board gameBoard;
    GamePiece userPiece = GamePiece("", false);
    GamePiece computerPiece = GamePiece("", false);
    std::string userInput(std::string);
    void determinePlayerPiece();
    void computersTurn();
    void moveTo(); //Attempt to move a piece to a location, also asking the question in the method
    int checkForWinner(); //If response > 0, that player won
    bool catsGame();
public:
    void playGame();
};

#endif /* Game_hpp */

