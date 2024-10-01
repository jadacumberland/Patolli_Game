#include "Referee.h"

using namespace std;

Referee::Referee() {
    board = Board();
    // Initialize Player L and N
    players[0] = Player('L');
    players[1] = Player('N');
    // Start with Player L's turn
    currentPlayer = 0;
    otherPlayer = 1;
}

int Referee::rollDice() {
    return rand() % 6;
}

void Referee::startGame() {
    while (players[0].getPiecesWon() < 6 && players[1].getPiecesWon() < 6) {
        // Roll Dice
        char pieceToMove;
        int rollAmt = rollDice();

        // Output current status
        cout << board << endl << endl;
        cout << "Player " << players[0].getIdentifier() << " Score: " << players[0].getPiecesWon() << endl;
        cout << "Player " << players[1].getIdentifier() << " Score: " << players[1].getPiecesWon() << endl << endl;

        // Prompt user for input and save
        Prompt:
            cout << "It is Player " << players[currentPlayer].getIdentifier() << "'s turn." << endl;
            cout << "Your roll is: " << rollAmt << endl;
            cout << "Which piece would you like to move?" << players[currentPlayer].getPiecesString() << endl;
            cin >> pieceToMove;

        bool isValidPlayerPiece = false;
        // Check if piece is player's
        for (int i = 0; i < 7; i ++) {
            if (players[currentPlayer].getPiece(i) == pieceToMove) {
                isValidPlayerPiece = true;
                break;
            }
        }

        // Check if piece has been won
        for (char piece: wonPieces)
            if(pieceToMove == piece)
                isValidPlayerPiece = false;

        // Check if piece is already on board
        int oldSpot = board.getSpotOfPiece(pieceToMove);
        bool pieceExists = oldSpot >= 0;
        int newSpot;

        // Initialize newSpot
        if (pieceExists)
            newSpot = (oldSpot + rollAmt) % 60;
        else
            newSpot = players[currentPlayer].getStartPos();

        // Determine if it's moving to a specialSpot
        bool isSpecialSpot = (newSpot == 7 || newSpot == 22 || newSpot == 37 || newSpot == 52);

        // Get status of spot piece is moving to
        bool spotFilled = board.getPieceInSpot(newSpot) != ' ' && !isSpecialSpot;

        // Skip movement if turn is forfeit
        if (pieceToMove == '0')
            goto NextTurn;

        // Check for validity of input
        if (cin.fail() || !isValidPlayerPiece || spotFilled || (pieceExists && oldSpot < players[currentPlayer].getEndPos() && newSpot > players[currentPlayer].getEndPos())) {
            cin.ignore(10000, '\n');
            cin.clear();
            cout << "You have made an illegal move. Please try again." << endl;
            goto Prompt;
        }

        // Move piece to new spot
        board.setPieceInSpot(oldSpot, ' ');

        if (newSpot == players[currentPlayer].getEndPos()) {
            wonPieces[players[currentPlayer].getPiecesWon() + players[otherPlayer].getPiecesWon()] = pieceToMove;
            players[currentPlayer].pieceWon();
        }
        else
            board.setPieceInSpot(newSpot, pieceToMove);

        // Move to next turn
        NextTurn:
            // Determine if it's moving to a bonusSpot
            bool isBonusSpot = (newSpot == 0 || newSpot == 14 || newSpot == 15 || newSpot == 29 || newSpot == 30 || newSpot == 44 || newSpot == 45 || newSpot == 59);

            // Change turn to next player if piece isn't on bonus spot
            if (!isBonusSpot) {
                int tempOther = otherPlayer;
                otherPlayer = currentPlayer;
                currentPlayer = tempOther;
            }
    }

    // Congratulate the winning player
    cout << "Congratulations Player";
    if (players[0].getPiecesWon() == 6)
        cout << players[0].getIdentifier();
    else
        cout << players[1].getIdentifier();
    cout << "! You won the game! The final score was " << players[0].getPiecesWon() << "-" << players[1].getPiecesWon() << ".";
}