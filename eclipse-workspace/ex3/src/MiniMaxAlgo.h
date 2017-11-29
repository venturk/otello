/*
 * Kfir Ventura
 * Avihay Arzuan
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
    static void useMiniMaxMove(GameLogic *logic, map<string,Cell> posMoves, char color,char opponentColor, Board * board);
};

#endif /* MINIMAXLOGIC_H_ */
