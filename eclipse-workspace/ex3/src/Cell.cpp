/*
* Kfir Ventura
* 301754370
*/
#include "Cell.h"

Cell::Cell(Point point, char color) : point(point.getRow(), point.getCol()),
                                      color(color) {}

Cell::Cell(int row, int col, char color) : point(row, col), color(color) {}

char Cell::getColor() const {
  return this->color;
}

void Cell::setColor(char color) {
  this->color = color;
}

string Cell::toString() const {
  return this->point.toString();
}

bool Cell::isFilledWith(char color) const {
  return (this->color == color);
}

bool Cell::isEmpty() const {
  return (this->color == EMPTY);
}

int Cell::getCol() const {
  return this->point.getCol();
}

int Cell::getRow() const {
  return this->point.getRow();
}

/**
 * SHOULD BE REMOVED...?
 */
bool Cell::isWhite() const {
  return (this->color == WHITE);
}

/**
 * SHOULD BE REMOVED...?
 */
bool Cell::isBlack() const {
  return (this->color == BLACK);
}

/**
 * SHOULD BE REMOVED...?
 */
Point Cell::getPoint() const {
  return this->point;
}