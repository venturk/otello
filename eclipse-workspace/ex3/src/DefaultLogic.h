/*
* Kfir Ventura
* 301754370
*/
#ifndef EX2_DEFAULTLOGIC_H
#define EX2_DEFAULTLOGIC_H

#include "GameLogic.h"

class DefaultLogic : public GameLogic {
 public:
  /**
   * Constructor.
   * @param board - the game's board.
   * @param currentColor - EMPTY.
   */
  DefaultLogic(Board *board, char currentColor = EMPTY);

  /**
   * The method calculates all possible moves for player
   * @param currentColor - the current player's color.
   * @return all possible moves of current player.
   */
  virtual CellMap *getPossibleMoves(char currentColor);

  /**
   * Destructor.
   */
  ~DefaultLogic();

  /**
   * The method flips all possible opponent's tiles.
   * The name of the method is a reference to the Star Wars Saga.
   * @param row - row's index to start from.
   * @param col - col's index to start from.
   */
  virtual void executeOrder66(int row, int col);

 private:
  /**
   * Members.
   */
  Cell *currentCell;
  char currentColor;
  CellMap *cellMap;
  CellMap *possibleMoves;
  Board* board;

  /**
   * Sub method that checks if the cell is out of boundaries.
   * @param row - row's index.
   * @param col - column's index.
   * @return true if the cell is out of boundaries, otherwise return false.
   */
  bool cellOutOfBounds(int row, int col) const;

  /**
   * Sub method that changes the color of all cells in the current direction.
   * @param rowDirection - row's direction.
   * @param colDirection - column's direction.
   */
  void flip(int rowDirection, int colDirection);

  /**
   * Sub method that check's if the cell should be added as a possible move.
   * @param rowDirection - the direction of the row to be checked.
   * @param colDirection - the direction of the column to be checked.
   * @return true if cell is a possible move of the current player, else false.
   */
  virtual bool isPossibleMove(int rowDirection, int colDirection) const;
};

#endif //EX2_DEFAULTLOGIC_H
