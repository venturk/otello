/*
* Kfir Ventura the great loser
* 301754370
*/
#ifndef EX2_BOARD_H
#define EX2_BOARD_H

#define CELL_SEPARATOR " | "
#define LINE_SEPARATOR "-"
#define LINE_SEPARATOR_SIZE ((this->size * 4) + 3)
#define MID_CELL_1 (this->size / 2)
#define MID_CELL_2 ((this->size / 2) + 1)
#define BOARD_SIZE 8

#include <iostream>
#include "Cell.h"
#include <map>
#include "CellMap.h"

using namespace std;

class Board {
 public:
  /**
   * @return a pointer to the map of cells.
   */
  CellMap *getCellsList() const;

  /**
   * @return size of the board.
   */
  int getSize() const;

  /**
 * Constructor.
 * @param size the board's size.
 */
  Board(int size = BOARD_SIZE);

  /**
   * Destructor.
   */
  ~Board();

  /**
 * The method prints the board.
 */
  void printBoard() const;
  
 private:
  /**
   * Members of the class.
   */
  const int size;
  CellMap *board;

  /**
 * The method prints a line from the board.
 * @param line - the line to be printed.
 * @param lineNumber - the index of the current line.
 */
  void printLine(int &lineNumber) const;

  /**
 * The method prints a separator-line.
 * A separator-line is a line which separates one row from another.
 */
  void printLineSeparator() const;

  /**
 * The method prints the first line BEFORE the board.
 * i.e the column's index.
 */
  void printFirstLine() const;

  /**
 * The method initializes the board.
 */
  void initBoard();
};

#endif //EX2_BOARD_H
