/*
 * AIPlayer.h
 *
 *  Created on: Nov 25, 2017
 *      Author: avihay
 */
#include "Player.h"
#include "GameLogic.h"
#include "MiniMaxAlgo.h"

#ifndef AIPLAYER_H_
#define AIPLAYER_H_

/*
 *
 */
class AIPlayer : public Player {
 public:
    AIPlayer(char color, Board * b);
    virtual ~AIPlayer() {};
    char getColor() const;
    void makeMove(GameLogic *logic, CellMap *posMoves, ConsoleMsgs *printer);

 private:
    const char color;
    Board * board;
};

#endif /* AIPLAYER_H_ */
