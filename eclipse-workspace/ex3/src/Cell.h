/*
 * Kfir Ventura
 * Avihay Arzuan
 */
#ifndef EX2_CELL_H
#define EX2_CELL_H

#define EMPTY ' '
#define BLACK 'X'
#define WHITE 'O'
#include "Point.h"

class Cell {
 public:
    Cell();
    /**
     * @return cell's coordinate.
     */
    Point getPoint() const;

    /**
     * @return true if cell's color is WHITE. otherwise, return false.
     */
    bool isWhite() const;

    /**
     * @return true if cell's color is BLACK. otherwise, return false.
     */
    bool isBlack() const;

    /**
     * @return cell's row index.
     */
    int getRow() const;

    /**
     * @return cell's column index.
     */
    int getCol() const;

    /**
     * @param color - the color to be compared with,
     * @return true if the cell's color is the same as color, else return false.
     */
    bool isFilledWith(char color) const;

    /**
     * @return true if cell's color is EMPTY. otherwise, return false.
     */
    bool isEmpty() const;

    /**
     * Constructor.
     * @param row - index of the row.
     * @param col - index of the column.
     * @param color - cell's color. by default, will be EMPTY.
     */
    Cell(int row, int col, char color = EMPTY);

    /**
     * Constructor.
     * @param point - coordinate of the cell (i.e cell[i,j])
     * @param color - cell's color may be BLACK, WHITE or EMPTY.
     */
    Cell(Point point, char color = EMPTY);

    /**
     * Getter.
     * @return cell's color.
     */
    char getColor() const;

    /**
     * Setter.
     * @param color - cell's color may be BLACK, WHITE or EMPTY.
     */
    void setColor(char color);

    /**
     * Getter.
     * @return cell's coordinate (i.e "(x,y)")
     */
    string toString() const;

 private:
    Point point;
    char color;
};

#endif //EX2_CELL_H
