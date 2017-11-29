/*
 * Kfir Ventura
 * Avihay Arzuan
 */
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include "ConsoleMsgs.h"
#include "GameLogic.h"

class Player {
 public:
    /**
     * A getter method.
     * @return the color of the player.
     */
    virtual char getColor() const = 0;

    /**
     * The method asks user's choice and responsible to execute it.
     * @param logic - rules of the game.
     * @param posMoves - the possible moves to choose from.
     * @param printer - the console printer.
     */
    virtual void makeMove(GameLogic *logic, map<string, Cell> &posMoves,
                          ConsoleMsgs printer)= 0;

    // D'tor.
    virtual ~Player() {
    }
};
#endif //EX2_PLAYER_H
