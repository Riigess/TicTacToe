//
//  Game.cpp
//  tic-tac-toe
//
//  Created by Austin on 1/8/21.
//

#include "Game.hpp"

std::string Game::userInput(std::string message) {
    std::cout << message << std::endl;
    std::cout << "> ";
    std::string userIn;
    std::cin >> userIn;
    return userIn;
}

void Game::determinePlayerPiece() {
    std::string xOrO = "L";
    bool hasRun = false;
    do {
        if(hasRun) {
            std::cout << "Try again. Please Type \"X\" or \"O\"" << std::endl;
        } else {
            std::cout << std::endl << std::endl;
        }
        std::cout << "Do you want to be Xs or Os? (X or O)" << std::endl;
        std::cout << "> ";
        std::cin >> xOrO;
        hasRun = true;
    } while(xOrO.compare("x") != 0 && xOrO.compare("X") != 0 && xOrO.compare("o") != 0 && xOrO.compare("O") != 0);

    userPiece = GamePiece(xOrO, true);

    if(userPiece.getPiece().compare("X") == 0) {
        computerPiece = GamePiece("O", 0);
    } else if(userPiece.getPiece().compare("x") == 0) {
        computerPiece = GamePiece("o", false);
    } else if(userPiece.getPiece().compare("o") == 0) {
        computerPiece = GamePiece("x", false);
    } else {
        computerPiece = GamePiece("X", false);
    }
}

void Game::moveTo() {
    int input;
    bool hasRun = false;
    do {
        if(hasRun) {
            std::cout << "Sorry, that's not available. Please try another space." << std::endl << std::endl;
        }
        gameBoard.printBoard();
        std::cout << std::endl << "Where would you like to move to? (1, 2, 3, ...)" << std::endl;
        std::cout << "> ";
        std::cin >> input;
        hasRun = true;
    } while(input > 0 && input < 10 && !gameBoard.canAddTo(input-1));
    gameBoard.addTo(input-1, userPiece);
}

int Game::checkForWinner() {
    bool diagonalOne = true;
    bool diagonalOneIsPlayer = true;
    bool diagonalTwo = true;
    bool diagonalTwoIsPlayer = true;
    // Board is always initialized to have 9 spaces
    for(int i = 0; i < 3; i++) {
        //Check Horizontal
        if(gameBoard.getBoardAt((i*3)).compare(gameBoard.getBoardAt((i*3) + 1)) == 0) {
            if(gameBoard.getBoardAt((i*3)+1).compare(gameBoard.getBoardAt((i*3)+2)) == 0) {
                return true;
            }
        }
        //Check Verticals
        if(gameBoard.getBoardAt(i).compare(gameBoard.getBoardAt(i+3)) == 0) {
            if(gameBoard.getBoardAt(i+3).compare(gameBoard.getBoardAt(i+6)) == 0) {
                return true;
            }
        }
        //Check Diagonals
        if(i == 0) {
            diagonalOneIsPlayer = gameBoard.getBoardAt((i*3) + i).isPlayer();
            diagonalTwoIsPlayer = gameBoard.getBoardAt(((i*2) + 2)).isPlayer();
        } else {
            if(gameBoard.getBoardAt((i*3) + i).isPlayer() != diagonalOneIsPlayer) {
                diagonalOne = false;
            }
            if(gameBoard.getBoardAt((i*2) + 2).isPlayer() != diagonalTwoIsPlayer) {
                diagonalTwo = false;
            }
        }
    }
    return diagonalOne || diagonalTwo;
}

bool Game::catsGame() {
    for(int i = 0; i < 9; i++) {
        if(gameBoard.getBoardAt(i).getPiece().compare(std::to_string(i+1)) == 0) {
            return false;
        }
    }
    std::cout << std::endl << "Draw!" << std::endl;
    return true;
}

void Game::computersTurn() {
    std::vector<int> remainingPositions;
    for(int i = 0; i < gameBoard.getBoardLength(); i++) {
        if(gameBoard.getBoardAt(i).getPiece().compare(std::to_string(i+1)) == 0) {
            remainingPositions.push_back(i);
        }
    }
    srand(time(0));
    int position = rand() % remainingPositions.size();
    if(remainingPositions.size() != 0) {
        gameBoard.addTo(remainingPositions.at(position), computerPiece);
    }
}

void Game::playGame() {
    std::cout << std::endl << std::endl << "Welcome to Tic-Tac-Toe!" << std::endl << "Written by Riigess." << std::endl;
    std::string temp;
    determinePlayerPiece();
    do {
        moveTo();
        computersTurn();
        std::cout << std::endl;
    } while(checkForWinner() == 0 && !catsGame());

    do {
        temp = userInput("\nWould you like to play again? (Y/n)");
    } while(temp.compare("y") != 0 && temp.compare("Y") != 0 && temp.compare("n") != 0 && temp.compare("N") != 0);
    if(temp.compare("y") == 0 || temp.compare("Y") == 0) {
        gameBoard = Board(); //Reset the board..
        playGame();
    }
}
