/*
 * Kfir Ventura
 * Avihay Arzuan
 */

#include "Point.h"

Point::Point(int row, int col) : row(row), col(col) {};

int Point::getRow() const {
  return this->row;
}

int Point::getCol() const {
  return this->col;
}

string Point::toString() const {
  return String::intToPoint(this->row, this->col);
}
