/*
 * Kfir Ventura
 * Avihay Arzuan
 */
#include "Board.h"

Board::Board(int size)
        : size(size) {
    this->board = &this->mapCell;
    initBoard();
}
Board::Board(const Board &obj) {
    this->size = obj.getSize();
    this->mapCell = *obj.getCellsList();
    this->board = &this->mapCell;
}
Board::~Board() {
    this->mapCell.clear();
    this->board = NULL;
}

map<string, Cell>* Board::getCellsList() const {
    return this->board;
}

void Board::initBoard() {
    for (int row = 1; row <= this->size; row++) {
        for (int col = 1; col <= this->size; col++) {
            Cell c(row, col);
            board->insert(pair<string, Cell>(String::intToPoint(row, col), c));
        }
    }
    board->at(String::intToPoint(MID_CELL_1, MID_CELL_1)).setColor(WHITE);
    board->at(String::intToPoint(MID_CELL_2, MID_CELL_2)).setColor(WHITE);
    board->at(String::intToPoint(MID_CELL_1, MID_CELL_2)).setColor(BLACK);
    board->at(String::intToPoint(MID_CELL_2, MID_CELL_1)).setColor(BLACK);
}

void Board::printBoard() const {
    printFirstLine();
    for (int i = 1; i <= this->size; printLine(i), i++)
        ;
    cout << endl;
}

void Board::printFirstLine() const {
    for (int i = 0; i <= this->size; i++) {
        if (i)
            cout << i;
        else
            cout << " ";
        cout << CELL_SEPARATOR;
    }
    printLineSeparator();
}

void Board::printLine(int &lineNumber) const {
    cout << lineNumber << CELL_SEPARATOR;
    for (int i = 1; i <= this->size; i++)
        cout << this->board->at(String::intToPoint(lineNumber, i)).getColor()
             << CELL_SEPARATOR;
    printLineSeparator();
}

void Board::printLineSeparator() const {
    cout << endl;
    for (int i = 0; i < LINE_SEPARATOR_SIZE; cout << LINE_SEPARATOR, i++)
        ;
    cout << endl;
}

int Board::getSize() const {
    return this->size;
}
