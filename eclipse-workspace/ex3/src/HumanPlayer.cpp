/*
* Kfir Ventura
* 301754370
*/
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(char color) : color(color) {}

char HumanPlayer::getColor() const {
  return this->color;
}

void HumanPlayer::makeMove(GameLogic *logic, CellMap *posMoves,
                           ConsoleMsgs *printer) {
  int row, col;

  do {
    cin >> row >> col;

    if (posMoves->isInMap(row, col))
      break;

    printer->illegalMove();
    printer->plsEnterMove();
  } while (true);

  logic->executeOrder66(row, col);
}
