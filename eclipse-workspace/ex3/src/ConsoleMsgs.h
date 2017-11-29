/*
 * Kfir Ventura
 * Avihay Arzuan
 */
#ifndef EX2_CONSOLEMSGS_H
#define EX2_CONSOLEMSGS_H

#include <iostream>
#include <limits>
#include "Board.h"

using namespace std;
typedef map<string, Cell>::iterator Iterator;

class ConsoleMsgs {
 public:
    /**
     * The method prints the given board.
     * @param board - the board to be printed.
     */
    void curBoard(Board *board) const;

    /**
     * The method prints a "it's your move" message.
     * @param currentColor - current player's color to play.
     */
    void itsYourMove(char currentColor) const;

    /**
     * The method prints all the current possible moves.
     * @param cellMap - the possible moves to be printed.
     */
    void posMoves(map<string, Cell> cellMap) const;

    /**
     * The method notifies the player that he/she doesn't have any possible moves.
     */
    void noPosMoves() const;

    /**
     * The method asks the player to choose a move.
     */
    void plsEnterMove() const;

    /**
     * The method notifies the player that he chose an illegal move.
     */
    void illegalMove() const;

    /**
     * The method prints the winner.
     * @param color - the color of the WINNER!!!
     */
    void printWinner(char color) const;
};

#endif //EX2_CONSOLEMSGS_H
