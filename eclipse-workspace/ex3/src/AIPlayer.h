/*
 * Kfir Ventura
 * Avihay Arzuan
 */
#include "Player.h"
#include "GameLogic.h"
#include "MiniMaxAlgo.h"

#ifndef AIPLAYER_H_
#define AIPLAYER_H_

/*
 * Inherit from player
 */
class AIPlayer : public Player {
 public:
    /**
     * c'tor
     * @param color the color of the player
     * @param b the board to make next moves calculations
     */
    AIPlayer(char color, Board * b);

    virtual ~AIPlayer() {
    };
    /**
     *
     * @return the player color
     */
    char getColor() const;
    /**
     * let the player make a move in the game
     * @param logic
     * @param posMoves
     * @param printer
     */
    void makeMove(GameLogic *logic, map<string, Cell> &posMoves, ConsoleMsgs printer);

 private:
    const char color;
    Board * board;
};

#endif /* AIPLAYER_H_ */
