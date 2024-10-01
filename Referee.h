#ifndef FINAL_PROJECT_REFEREE_H
#define FINAL_PROJECT_REFEREE_H

#include "Board.h"
#include "Player.h"

class Referee {
private:
    Board board;
    Player players[2];
    char wonPieces[12];
    int currentPlayer, otherPlayer;
public:
    Referee();

    int rollDice();
    void startGame();
};


#endif //FINAL_PROJECT_REFEREE_H
