#include <iostream>
#ifndef FINAL_PROJECT_BOARD_H
#define FINAL_PROJECT_BOARD_H

class Board {
private:
    char board[60];
public:
    Board();

    int getSpotOfPiece(char piece);
    char getPieceInSpot(int index);
    void setPieceInSpot(int index, char piece);

    friend std::ostream& operator<<(std::ostream& out, Board& board);
};


#endif //FINAL_PROJECT_BOARD_H
