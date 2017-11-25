/*
 * MiniMaxLogic.h
 *
 *  Created on: Nov 25, 2017
 *      Author: avihay
 */
#include "DefaultLogic.h"
#include "Cell.h"
#ifndef MINIMAXLOGIC_H_
#define MINIMAXLOGIC_H_

/*
 *
 */
class MiniMaxAlgo {
 public:
    static void useMiniMaxMove(GameLogic *logic, CellMap *posMoves, char color,char opponentColor, Board * board);
};

#endif /* MINIMAXLOGIC_H_ */
