/*
* Kfir Ventura
* 301754370
*/
#include "CellMap.h"

CellMap::CellMap() : cellMap(new map<string, Cell *>) {}

CellMap::CellMap(const CellMap* &obj) {
    this->cellMap = new map<string,Cell *>;
    for (Iterator it = obj->cellMap->begin(); it!= obj->cellMap->end(); it++) {
        this->insert(it->second);
    }
}

void CellMap::insert(int row, int col, char color) {
  Cell *cell = new Cell(row, col, color);
  cellMap->insert(pair<string, Cell *>(cell->toString(), cell));
}

void CellMap::insert(Cell *cell) {
  this->insert(cell->getRow(), cell->getCol(), cell->getColor());
}

Cell *CellMap::at(int row, int col) const {
  return cellMap->at(String::intToPoint(row, col));
}

void CellMap::setCellColor(int row, int col, char color) {
  this->at(row, col)->setColor(color);
}

void CellMap::flipCellColor(int row, int col) {
  if (this->at(row, col)->isEmpty())
    return;

  if (this->at(row, col)->isBlack())
    this->at(row, col)->setColor(WHITE);
  else
    this->at(row, col)->setColor(BLACK);
}

char CellMap::getCellColor(int row, int col) const {
  return this->at(row, col)->getColor();
}

map<string, Cell *>::iterator CellMap::begin() const {
  return this->cellMap->begin();
}

map<string, Cell *>::iterator CellMap::end() const {
  return this->cellMap->end();
}

int CellMap::getSize() const {
  return (int) this->cellMap->size();
}

CellMap::~CellMap() {
  for (Iterator iterator = this->cellMap->begin();
       iterator != this->cellMap->end(); iterator++)
    delete iterator->second; // deleting all cells
  delete this->cellMap;
}

bool CellMap::isInMap(int row, int col) const {
  for (Iterator iterator = this->begin(); iterator != this->end(); iterator++)
    if (iterator->second->getRow() == row && iterator->second->getCol() == col)
      return true;
  return false;
}
