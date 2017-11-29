/*
 * Kfir Ventura
 * Avihay Arzuan
 */
#ifndef EX2_GAMELOGIC_H
#define EX2_GAMELOGIC_H

//#include "CellMap.h"
#include "Board.h"

typedef enum Direction {
    stay,
    up,
    down = -1
} Direction;

class GameLogic {
 public:
    // D'tor
    virtual ~GameLogic() {
    }
    ;

    /**
     * The method calculates all possible moves for a player.
     * @param currentColor - the current player's color.
     * @return all possible moves of current player.
     */
    virtual map<string, Cell> getPossibleMoves(char currentColor) = 0;

    /**
     * The method flips all possible opponent's tiles.
     * The name of the method is a reference to the Star Wars Saga.
     * @param row - row's index to start from.
     * @param col - col's index to start from.
     */
    virtual void executeOrder66(int row, int col) = 0;

 private:
    /**
     * Sub method that checks if the cell is out of boundaries.
     * @param row - row's index.
     * @param col - column's index.
     * @return true if the cell is out of boundaries, otherwise return false.
     */
    virtual bool cellOutOfBounds(int row, int col) const = 0;

    /**
     * Sub method that changes the color of all cells in the current direction.
     * @param rowDirection - row's direction.
     * @param colDirection - column's direction.
     */
    virtual void flip(int rowDirection, int colDirection) = 0;

    /**
     * Sub method that check's if the cell should be added as a possible move.
     * @param rowDirection - the direction of the row to be checked.
     * @param colDirection - the direction of the column to be checked.
     * @return true if cell is a possible move of the current player, else false.
     */
    virtual bool isPossibleMove(int rowDirection, int colDirection) const = 0;
};

#endif //EX2_GAMELOGIC_H
