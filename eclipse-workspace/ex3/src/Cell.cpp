/*
 * Kfir Ventura
 * Avihay Arzuan
 */
#include "Cell.h"

Cell::Cell()
        : point(Point(0, 0)),
          color(EMPTY) {
}
Cell::Cell(Point point, char color)
        : point(point.getRow(), point.getCol()),
          color(color) {
}

Cell::Cell(int row, int col, char color)
        : point(row, col),
          color(color) {
}

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
