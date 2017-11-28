/*
 * Kfir Ventura
 * 301754370
 */
#include "DefaultLogic.h"

DefaultLogic::DefaultLogic(Board *board, char currentColor) {
    this->board = board;
    this->currentColor = currentColor;
    this->cellMap = board->getCellsList();
    this->possibleMoves = new CellMap();
    this->currentCell = NULL;
}
DefaultLogic::DefaultLogic(DefaultLogic &obj) {
    Board * b = obj.getLogicBoard();
    Cell * c = obj.currentCell;
    CellMap *cm  = obj.getCellMap();
    CellMap *pm = obj.clonePossibleMoves();
    this->board = new Board(*b);
    this->currentColor = obj.getCurrentColor();
    this->cellMap = new CellMap(*cm);
    this->possibleMoves= new CellMap(*pm);
    this->currentCell = c;
}

DefaultLogic::~DefaultLogic() {
//    delete this->cellMap;
    delete this->possibleMoves;
}

Board * DefaultLogic::getLogicBoard() const {
    return this->board;
}
char DefaultLogic::getCurrentColor() const {
    return this->currentColor;
}
Cell * DefaultLogic::getCurrentCell() const {
    return this->getCurrentCell();
}
CellMap * DefaultLogic::clonePossibleMoves() const {
    return this->possibleMoves;
}
CellMap * DefaultLogic::getCellMap() const {
    return this->cellMap;
}

CellMap *DefaultLogic::getPossibleMoves(char currentColor) {
    delete possibleMoves;
    possibleMoves = new CellMap();
    this->currentColor = currentColor;

    // Iterate over all cells
    for (Iterator iterator = this->cellMap->begin();
            iterator != this->cellMap->end(); iterator++) {

        // Check for possible moves ONLY if cell is empty
        if (iterator->second->isEmpty()) {
            this->currentCell = iterator->second;

            // if ANY direction is a possible move, ADD current cell into the map
            if (isPossibleMove(up, up) || isPossibleMove(down, down)
                    || isPossibleMove(up, down) || isPossibleMove(down, up)
                    || isPossibleMove(up, stay) || isPossibleMove(stay, up)
                    || isPossibleMove(down, stay) || isPossibleMove(stay, down))
                possibleMoves->insert(iterator->second);
        }
    }

    // return all possible moves
    return possibleMoves;
}

bool DefaultLogic::isPossibleMove(int rowDirection, int colDirection) const {
    int row = currentCell->getRow();
    int col = currentCell->getCol();
    bool isFirstCell = true;

    do {
        row += rowDirection;
        col += colDirection;

        if (cellOutOfBounds(row, col))
            return false;

        if (cellMap->at(row, col)->isFilledWith(this->currentColor)) {
            if (isFirstCell)
                return false;
            return true;
        }

        if (cellMap->at(row, col)->isEmpty())
            return false;

        isFirstCell = false;
    } while (true);
}

void DefaultLogic::executeOrder66(int row, int col) {
    this->currentCell = this->cellMap->at(row, col);
    this->currentCell->setColor(this->currentColor);

    for (int i = down; i <= up; i++)
        for (int j = down; j <= up; j++)
            if (isPossibleMove(i, j))
                flip(i, j);
}

void DefaultLogic::flip(int rowDirection, int colDirection) {
    int row = this->currentCell->getRow() + rowDirection;
    int col = this->currentCell->getCol() + colDirection;

    do {
        this->cellMap->flipCellColor(row, col);
        row += rowDirection;
        col += colDirection;
    } while (!(this->cellMap->at(row, col)->isFilledWith(this->currentColor)));
}

bool DefaultLogic::cellOutOfBounds(int row, int col) const {
    return ((row < 1) || (col < 1) || (row > this->board->getSize())
            || (col > this->board->getSize()));
}

