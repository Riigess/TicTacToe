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
    //Top Row:
    if(gameBoard.getBoardAt(0).getPiece().compare(gameBoard.getBoardAt(1).getPiece()) == 0 &&
       gameBoard.getBoardAt(0).getPiece().compare(gameBoard.getBoardAt(2).getPiece()) == 0) {
        std::cout << gameBoard.getBoardAt(0).getPiece() << " wins!" << std::endl;
        return gameBoard.getBoardAt(0).isPlayer() + 1;
    }
    //Middle row:
    else if(gameBoard.getBoardAt(3).getPiece().compare(gameBoard.getBoardAt(4).getPiece()) == 0 &&
            gameBoard.getBoardAt(3).getPiece().compare(gameBoard.getBoardAt(5).getPiece()) == 0) {
        std::cout << gameBoard.getBoardAt(3).getPiece() << " wins!" << std::endl;
        return gameBoard.getBoardAt(3).isPlayer() + 1;
    }
    //Bottom row:
    else if(gameBoard.getBoardAt(6).getPiece().compare(gameBoard.getBoardAt(7).getPiece()) == 0 &&
            gameBoard.getBoardAt(6).getPiece().compare(gameBoard.getBoardAt(8).getPiece()) == 0) {
        std::cout << gameBoard.getBoardAt(6).getPiece() << " wins!" << std::endl;
        return gameBoard.getBoardAt(6).isPlayer() + 1;
    }
    //Left column:
    else if(gameBoard.getBoardAt(0).getPiece().compare(gameBoard.getBoardAt(3).getPiece()) == 0 &&
            gameBoard.getBoardAt(0).getPiece().compare(gameBoard.getBoardAt(6).getPiece()) == 0) {
        std::cout << gameBoard.getBoardAt(0).getPiece() << " wins!" << std::endl;
        return gameBoard.getBoardAt(0).isPlayer() + 1;
    }
    //Middle column:
    else if(gameBoard.getBoardAt(1).getPiece().compare(gameBoard.getBoardAt(4).getPiece()) == 0 &&
            gameBoard.getBoardAt(1).getPiece().compare(gameBoard.getBoardAt(7).getPiece()) == 0) {
        std::cout << gameBoard.getBoardAt(1).getPiece() << " wins!" << std::endl;
        return gameBoard.getBoardAt(1).isPlayer() + 1;
    }
    //Right column:
    else if(gameBoard.getBoardAt(2).getPiece().compare(gameBoard.getBoardAt(5).getPiece()) == 0 &&
            gameBoard.getBoardAt(2).getPiece().compare(gameBoard.getBoardAt(8).getPiece()) == 0) {
        std::cout << gameBoard.getBoardAt(2).getPiece() << " wins!" << std::endl;
        return gameBoard.getBoardAt(2).isPlayer() + 1;
    }
    //Diagnoal right:
    else if(gameBoard.getBoardAt(0).getPiece().compare(gameBoard.getBoardAt(4).getPiece()) == 0 &&
            gameBoard.getBoardAt(0).getPiece().compare(gameBoard.getBoardAt(8).getPiece()) == 0) {
        std::cout << gameBoard.getBoardAt(0).getPiece() << " wins!" << std::endl;
        return gameBoard.getBoardAt(0).isPlayer() + 1;
    }
    //Diagonal left:
    else if(gameBoard.getBoardAt(2).getPiece().compare(gameBoard.getBoardAt(4).getPiece()) == 0 &&
            gameBoard.getBoardAt(2).getPiece().compare(gameBoard.getBoardAt(7).getPiece()) == 0) {
        std::cout << gameBoard.getBoardAt(2).getPiece() << " wins!" << std::endl;
        return gameBoard.getBoardAt(2).isPlayer() + 1;
    }
    return 0;
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
