/*
 * Kfir Ventura
 * Avihay Arzuan
 */
#include "DefaultLogic.h"

DefaultLogic::DefaultLogic(Board *board, char currentColor) {
    Board * b = board;
    this->board = new Board(*b);
    this->boardSize = this->board->getSize();
    this->currentColor = currentColor;
    this->cellMap = board->getCellsList();
    Cell c;
    this->currentCell = c;
}

DefaultLogic::DefaultLogic(DefaultLogic &obj) {
    this->board = NULL;
    this->currentColor = 0;
    this->cellMap = NULL;
    obj.copyLogic(this, obj);
    this->boardSize = this->board->getSize();
}
void DefaultLogic::copyLogic(DefaultLogic *l1, DefaultLogic &l2) {
    Board *b = l2.getLogicBoard();
    Cell c = l2.currentCell;
    map<string, Cell> *cm = l2.getCellMap();
    l1->board = new Board(*b);
    l1->currentColor = l2.getCurrentColor();
    l1->cellMap = new map<string, Cell>(*cm);
    l1->possibleMoves = l2.clonePossibleMoves();
    l1->currentCell = c;
}

DefaultLogic::~DefaultLogic() {
    if (this->cellMap) {
        delete this->cellMap;
    }
    delete this->board;
}

Board * DefaultLogic::getLogicBoard() const {
    return this->board;
}
char DefaultLogic::getCurrentColor() const {
    return this->currentColor;
}
Cell DefaultLogic::getCurrentCell() const {
    return this->getCurrentCell();
}
map<string, Cell> DefaultLogic::clonePossibleMoves() const {
    return this->possibleMoves;
}
map<string, Cell>* DefaultLogic::getCellMap() const {
    return this->cellMap;
}

map<string, Cell> DefaultLogic::getPossibleMoves(char currentColor) {
//    delete possibleMoves;
    map<string, Cell> possibleMoves;
    this->currentColor = currentColor;

    // Iterate over all cells
    for (Iterator iterator = this->cellMap->begin();
            iterator != this->cellMap->end(); iterator++) {

        // Check for possible moves ONLY if cell is empty
        if (iterator->second.isEmpty()) {
            this->currentCell = iterator->second;

            // if ANY direction is a possible move, ADD current cell into the map
            if (isPossibleMove(up, up) || isPossibleMove(down, down)
                    || isPossibleMove(up, down) || isPossibleMove(down, up)
                    || isPossibleMove(up, stay) || isPossibleMove(stay, up)
                    || isPossibleMove(down, stay)
                    || isPossibleMove(stay, down)) {
                int row, col;
                row = iterator->second.getRow();
                col = iterator->second.getCol();
                possibleMoves.insert(
                        pair<string, Cell>(String::intToPoint(row, col),
                                           iterator->second));
            }
        }
    }
    // return all possible moves
    return possibleMoves;
}

bool DefaultLogic::isPossibleMove(int rowDirection, int colDirection) const {
    int row = currentCell.getRow();
    int col = currentCell.getCol();
    bool isFirstCell = true;

    do {
        row += rowDirection;
        col += colDirection;

        if (cellOutOfBounds(row, col))
            return false;

        if (cellMap->at(String::intToPoint(row, col)).getColor()
                == (this->currentColor)) {
            if (isFirstCell)
                return false;
            return true;
        }

        if (cellMap->at(String::intToPoint(row, col)).isEmpty())
            return false;

        isFirstCell = false;
    } while (true);
}

void DefaultLogic::executeOrder66(int row, int col) {
    this->currentCell = this->cellMap->at(String::intToPoint(row, col));
    this->cellMap->at(String::intToPoint(row, col)).setColor(
            this->currentColor);

    for (int i = down; i <= up; i++)
        for (int j = down; j <= up; j++)
            if (isPossibleMove(i, j))
                flip(i, j);
}

void DefaultLogic::flip(int rowDirection, int colDirection) {
    int row = this->currentCell.getRow() + rowDirection;
    int col = this->currentCell.getCol() + colDirection;

    do {
        if (this->cellMap->at(String::intToPoint(row, col)).getColor() == WHITE) {
            this->cellMap->at(String::intToPoint(row, col)).setColor(BLACK);
        } else {
            this->cellMap->at(String::intToPoint(row, col)).setColor(WHITE);
        }
        row += rowDirection;
        col += colDirection;
    } while (!(this->cellMap->at(String::intToPoint(row, col)).getColor()
            == (this->currentColor)));
}

bool DefaultLogic::cellOutOfBounds(int row, int col) const {
    return ((row < 1) || (col < 1) || (row > this->boardSize)
            || (col > this->boardSize));
}
