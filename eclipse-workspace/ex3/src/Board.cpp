
/*
* Kfir Ventura the loser.
=======
/*ss
* Kfir Ven


* 301754370
*/
#include "Board.h"

Board::Board(int size) : size(size), board(new CellMap()) {
  initBoard();
}

CellMap *Board::getCellsList() const {
  return this->board;
};

void Board::initBoard() {
  for (int row = 1; row <= this->size; row++) {
    for (int col = 1; col <= this->size; col++) {
      board->insert(row, col);
    }
  }

  board->setCellColor(MID_CELL_1, MID_CELL_1, WHITE);
  board->setCellColor(MID_CELL_2, MID_CELL_2, WHITE);
  board->setCellColor(MID_CELL_1, MID_CELL_2, BLACK);
  board->setCellColor(MID_CELL_2, MID_CELL_1, BLACK);
}

void Board::printBoard() const {
  printFirstLine();
  for (int i = 1; i <= this->size; printLine(i), i++);
  cout << endl;
}

void Board::printFirstLine() const {
  for (int i = 0; i <= this->size; i++) {
    if (i)
      cout << i;
    else
      cout << " ";
    cout << CELL_SEPARATOR;
  }
  printLineSeparator();
}

void Board::printLine(int &lineNumber) const {
  cout << lineNumber << CELL_SEPARATOR;
  for (int i = 1; i <= this->size; i++)
    cout << this->board->getCellColor(lineNumber, i) << CELL_SEPARATOR;
  printLineSeparator();
}

void Board::printLineSeparator() const {
  cout << endl;
  for (int i = 0; i < LINE_SEPARATOR_SIZE; cout << LINE_SEPARATOR, i++);
  cout << endl;
}

int Board::getSize() const {
  return this->size;
}

Board::~Board() {
  delete this->board;
}
