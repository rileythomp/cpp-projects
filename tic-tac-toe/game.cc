#include <string>
#include <iostream>
#include "game.h"

void Game::turnMessage() {
    if (turn) {std::cout << 'X';} 
    else {std::cout << 'O';}
    std::cout << "'s turn, enter a move!" << std::endl;
}

void Game::update(int move) {
    if (board.isPlayed(move)) {std::cout << "Already played! Try again" << std::endl;} 
    else {
        board.update(move, turn);
        turn = !turn;
        moves++;
        printBoard();
    }
}

void Game::printDraw() {
    std::cout << "Cat's game!" << std::endl;
    std::cout << "Type new to play again or quit to exit" << std::endl << std::endl;
}

void Game::printWinner() {
    if (!turn) {std::cout << 'X';} 
    else { std::cout << 'O'; }
    std::cout << " wins!" << std::endl;
    std::cout << "Type new to play again or quit to exit" << std::endl << std::endl;
}

void Game::printBoard() {board.print();}

bool Game::hasWinner() {
    for (int i = 0; i < 7; ++i) {
        if (!board.isPlayed(i)) {continue;}
        if (i%3 == 0) {
            if (board.getVal(i) == board.getVal(i+1) && 
                board.getVal(i) == board.getVal(i+2)) {
                return true;
            }
        }
        if (i < 3) {
            if (board.getVal(i) == board.getVal(i+3) && 
                board.getVal(i) == board.getVal(i+6)) {
                return true;
            }
        }
        if (i == 0) {
            if (board.getVal(i) == board.getVal(i+4) && 
                board.getVal(i) == board.getVal(i+8)) {
                return true;
            }
        }
        if (i == 2) {
            if (board.getVal(i) == board.getVal(i+2) && 
                board.getVal(i) == board.getVal(i+4)) {
                return true;
            }
        }
    }
    return false;
}

int Game::numMoves() {return moves;}