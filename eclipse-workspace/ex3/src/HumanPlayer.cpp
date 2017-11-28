/*
 * Kfir Ventura
 * 301754370
 */
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(char color)
        : color(color) {
}

char HumanPlayer::getColor() const {
    return this->color;
}

void HumanPlayer::makeMove(GameLogic *logic, CellMap *posMoves,
                           ConsoleMsgs *printer) {
    int row, col;

    do {
        cout << "please enter row: " << endl;
        cin >> row;
        int x = isdigit(row);
        if (x==0) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "please enter column: " << endl;
            cin >> col;
            if (isdigit(col)==0) {
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                if (posMoves->isInMap(row, col))
                    break;
            }
        }

        printer->illegalMove();
        //printer->plsEnterMove();
    } while (true);

    logic->executeOrder66(row, col);
}
