#include <cstring>
#include "Player.h"

Player::Player(char charIdentifier) {
    identifier = charIdentifier;
    piecesWon = 0;

    // Assign values for Player L
    if (identifier == 'L') {
        std::strcpy(pieceArray, "ABCDEF");
        startPos = 23;
        endPos = 21;
    }
    // Assign values for Player N
    else if (identifier == 'N') {
        std::strcpy(pieceArray, "123456");
        startPos = 53;
        endPos = 51;
    }
    // Assign default values
    else {
        std::strcpy(pieceArray, "000000");
        startPos = 0;
        endPos = 0;
    }

    // Change final element from \0 to 0
    pieceArray[6] = '0';
}

char Player::getPiece(int index) {
    return pieceArray[index];
}

void Player::pieceWon() {
    piecesWon ++;
}

int Player::getPiecesWon() {
    return piecesWon;
}

int Player::getStartPos() {
    return startPos;
}

int Player::getEndPos() {
    return endPos;
}

char Player::getIdentifier() {
    return identifier;
}

std::string Player::getPiecesString() {
    std::string arrayString = "[";
    // Add each piece in array to string
    for (char piece:pieceArray) {
        arrayString += piece;
        arrayString += piece == '0' ? " (for no move)]" : ",";
    }
    return arrayString + "]";
}