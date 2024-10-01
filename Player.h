#ifndef FINAL_PROJECT_PLAYER_H
#define FINAL_PROJECT_PLAYER_H


#include <string>

class Player {
private:
    char pieceArray[7];
    char identifier;
    int piecesWon;
    int startPos;
    int endPos;
public:
    Player(char charIdentifier = '0');

    std::string getPiecesString();
    char getPiece(int index);
    void pieceWon();
    char getIdentifier();
    int getPiecesWon();
    int getStartPos();
    int getEndPos();
};


#endif //FINAL_PROJECT_PLAYER_H
