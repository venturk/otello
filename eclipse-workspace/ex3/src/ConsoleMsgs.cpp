/*
 * Kfir Ventura
 * Avihay Arzuan
 */
#include "ConsoleMsgs.h"

void ConsoleMsgs::noPosMoves() const {
    cout << "No possible moves. Play passes back to the other player." << endl;
}

void ConsoleMsgs::itsYourMove(char currentColor) const {
    cout << currentColor << ": It's your move." << endl;
}

void ConsoleMsgs::curBoard(Board *board) const {
    cout << "Current board:" << endl << endl;
    board->printBoard();
}

void ConsoleMsgs::posMoves(map<string, Cell> cellMap) const {
    Iterator iterator = cellMap.begin();

    cout << "Your possible moves: " << iterator->first;

    while (iterator != cellMap.end()) {
        iterator++;
        if (iterator != cellMap.end())
            cout << "," << iterator->first;
    }

    cout << endl << endl;
}
void ConsoleMsgs::plsEnterMove() const {
    cout << "Please enter your move row,col: ";
}

void ConsoleMsgs::printWinner(char color) const {
    if (color == EMPTY)
        cout << "THERE IS A TIE! WHAT A WASTE OF TIME...";
    else {
        cout << "AND THE WINNER IS... *DRUMS* ... ";
        if (color == BLACK)
            cout << BLACK;
        else
            cout << WHITE;
    }
    cout << endl;
}

void ConsoleMsgs::illegalMove() const {
    cout << "Illegal move!" << endl;
}
