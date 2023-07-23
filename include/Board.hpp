//
//  Board.hpp
//  tic-tac-toe
//
//  Created by Austin on 1/8/21.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "GamePiece.hpp"

class Board {
private:
    std::vector<GamePiece> gamePieces;
public:
    bool canAddTo(int);
    bool addTo(int, GamePiece);
    Board(std::vector<GamePiece>);
    Board();
    void printBoard();
    GamePiece getBoardAt(int);
    int getBoardLength();
};

#endif /* Board_hpp */
