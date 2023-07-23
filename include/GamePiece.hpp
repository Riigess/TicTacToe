//
//  GamePiece.hpp
//  tic-tac-toe
//
//  Created by Austin on 1/8/21.
//

#ifndef GamePiece_hpp
#define GamePiece_hpp

#include <stdio.h>
#include <string>

class GamePiece {
private:
    bool isGamePlayer;
    std::string pieceRep;
public:
    GamePiece(std::string, bool);
    bool isPlayer();
    std::string getPiece();
};

#endif /* GamePiece_hpp */

