#include <iomanip>
#include "Board.h"

Board::Board() {
    // Fill board array with spaces
    for (char &character:board) {
        character = ' ';
    }
}

char Board::getPieceInSpot(int index) {
    return board[index];
}

void Board::setPieceInSpot(int index, char piece) {
    board[index] = piece;
}

std::ostream &operator<<(std::ostream &out, Board &board) {
    // Output top spoke
    for (int i = 0; i < 7; i ++) {
        out << "              -----" << std::endl;
        out << "              |";
        out << board.getPieceInSpot(59 - i) << "|";
        out << board.getPieceInSpot(i) << "|";
        out << std::endl;
    }

    out << std::setfill('-') << std::setw(33) << "" << std::endl;
    // Output top left of middle bar
    for (int i = 0; i < 8; i ++) {
        out << "|" << board.getPieceInSpot(45 + i);
    }

    // Output top right of middle bar
    for (int i = 0; i < 8; i ++) {
        out << "|" << board.getPieceInSpot(7 + i);
    }
    out << "|" << std::endl;

    out << std::setfill('-') << std::setw(33) << "" << std::endl;

    // Output bottom left of middle bar
    for (int i = 0; i < 8; i ++) {
        out << "|" << board.getPieceInSpot(44 - i);
    }

    // Output bottom right of middle bar
    for (int i = 0; i < 8; i ++) {
        out << "|" << board.getPieceInSpot(22 - i);
    }
    out << "|" << std::endl;

    out << std::setfill('-') << std::setw(33) << "" << std::endl;

    // Output bottom spoke
    for (int i = 0; i < 7; i ++) {
        out << "              |";
        out << board.getPieceInSpot(36 - i) << "|";
        out << board.getPieceInSpot(23 + i) << "|" << std::endl;
        out << "              -----" << std::endl;
    }

    return out;
}

int Board::getSpotOfPiece(char piece) {
    // Return -1 if piece not on board
    int currentIndex = -1;

    // Iterate through board to find index of piece
    for (int i = 0; i < 60; i ++) {
        if (board[i] == piece)
            currentIndex = i;
    }

    return currentIndex;
}
