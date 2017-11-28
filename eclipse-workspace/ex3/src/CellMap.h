/*
 * Kfir Ventura
 * 301754370
 */
#ifndef EX2_CELLMAP_H
#define EX2_CELLMAP_H

#include <map>
#include "Cell.h"
#include <string>

using namespace std;

// for convenience reasons
typedef map<string, Cell *>::iterator Iterator;

class CellMap {
 public:
    // C'tor
    CellMap();

    CellMap(const CellMap &obj);

    // Identical to the "at" method of a regular map
    Cell *at(int row, int col) const;

    // Identical to the "insert" method of a regular map
    void insert(int row, int col, char color = EMPTY);

    // The method sets a cell's color in a given row & col
    void setCellColor(int row, int col, char color);

    // The method is a getter for cell's color in a given row & col
    char getCellColor(int row, int col) const;

    // The method returns true if a cell with a given row & col indexes is in map
    bool isInMap(int row, int col) const;

    // The method returns true if a cell with a given row & col indexes (as string) is in map
    bool isInMap(string rowCommaCol) const;

    bool count(string str) const;

    // D'tor
    ~CellMap();

    // Identical to the "insert" method of a regular map
    void insert(Cell* cell);

    // The method enables to change a cell's color in a given row & col
    void flipCellColor(int row, int col);

    // return the size of the map
    int getSize() const;

    // return a pointer to the beginning of the map
    map<string, Cell *>::iterator begin() const;

    // return a pointer to the end of the map
    map<string, Cell *>::iterator end() const;
 private:
    // members
    map<string, Cell *> *cellMap;
};

#endif //EX2_CELLMAP_H
