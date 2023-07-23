//
//  GamePiece.cpp
//  tic-tac-toe
//
//  Created by Austin on 1/8/21.
//

#include "GamePiece.hpp"

GamePiece::GamePiece(std::string piece, bool isPlayer) {
    pieceRep = piece;
    isGamePlayer = isPlayer;
}

bool GamePiece::isPlayer() {
    return isGamePlayer;
}

std::string GamePiece::getPiece() {
    return pieceRep;
}
