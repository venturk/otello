/*
 * Kfir Ventura
 * Avihay Arzuan
 */
#ifndef EX2_POINT_H
#define EX2_POINT_H

#include <cstdio>
#include "String.h"

class Point {
 public:
  /**
   * Constructor.
   * @param row - index of row.
   * @param col - index of column.
   */
  Point(int row, int col);

  /**
   * @return row's index.
   */
  int getRow() const;

  /**
   * @return column's index.
   */
  int getCol() const;

  /**
   * @return coordinates in string format: "(row,col)".
   */
  string toString() const;

 private:
  /**
   * Members.
   */
  int row, col;
};

#endif //EX2_POINT_H
