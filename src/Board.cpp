//
//  Board.cpp
//  tic-tac-toe
//
//  Created by Austin on 1/8/21.
//

#include "Board.hpp"

Board::Board(std::vector<GamePiece> gamePieces) {
    this->gamePieces = gamePieces;
}

Board::Board() {
    for(int i = 0; i < 9; i++) {
        gamePieces.push_back(GamePiece(std::to_string(i + 1), false));
    }
}

bool Board::canAddTo(int position) {
    std::string gamePiece = gamePieces.at(position).getPiece();
    return !(gamePiece.compare("x") == 0 || gamePiece.compare("X") == 0 || gamePiece.compare("o") == 0 || gamePiece.compare("O") == 0); //If it is any of those, we want it to return false, so ! is used to invert the output
}

bool Board::addTo(int position, GamePiece piece) {
    if(canAddTo(position)) {
        gamePieces.at(position) = piece;
        return true;
    } else {
        return false;
    }
}

int Board::getBoardLength() {
    return gamePieces.size();
}

GamePiece Board::getBoardAt(int position) {
    if(position < gamePieces.size()) {
        return gamePieces.at(position);
    }
    return GamePiece("-1", false);
}

void Board::printBoard() {
    //Print out the board:
    for(int i = 0; i < gamePieces.size(); i++) {
        //Print data from vector/array
        std::cout << " " << gamePieces.at(i).getPiece();
        if((i+1) % 3 == 0) { //Make it so we format the output lines during print
            std::cout << std::endl;
            if(i < 8) { //Make it so this line doesn't print on the last line of the application
                std::cout << "--- --- --- " << std::endl;
            }
        } else {
            std::cout << " |"; //Separate the numbers if this isn't the line we're outputting on
        }
    }
}
