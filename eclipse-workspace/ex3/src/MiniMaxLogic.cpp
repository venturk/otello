/*
 * MiniMaxLogic.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author: avihay
 */

#include "MiniMaxAlgo.h"

void MiniMaxAlgo::useMiniMaxMove(GameLogic *logic, CellMap *posMoves,
                                 char color, char opponentColor,
                                 Board * board) {
    int chosenRow = 0, chosenCol = 0, maxScoreRow = 0, maxScoreCol = 0;
    int minOppScore = 1000, score = -1000;
    //iterates each possible move of the player
    for (Iterator it = posMoves->begin(); it != posMoves->end(); it++) {
        Board *tempBoard = new Board(*board);
        GameLogic *tempLogic = new DefaultLogic(tempBoard, color);
        CellMap * tempPosMoves;
        int row, col;
        row = it->second->getRow();
        col = it->second->getCol();
        //make the possible move
        tempLogic->executeOrder66(row, col);
        tempPosMoves = tempLogic->getPossibleMoves(opponentColor);
        // iterates the opponent moves after making one of the possible moves
        for (Iterator innerIt = tempPosMoves->begin();
                innerIt != tempPosMoves->end(); innerIt++) {
            Board* tempInnerBoard = new Board(*tempBoard);
            GameLogic *tempInnerLogic = new DefaultLogic(tempInnerBoard,
                                                         opponentColor);
            int innerRow = innerIt->second->getRow();
            int innerCol = innerIt->second->getCol();
            //make one of the opponent move
            tempInnerLogic->executeOrder66(innerRow, innerCol);
            CellMap cells = * tempInnerBoard->getCellsList();
            int myColor = 0, oppColor = 0;
            //counts the difference
            for (Iterator i = cells.begin(); i != cells.end(); i++) {
                if (i->second->getColor() == color) {
                    myColor++;
                } else if (i->second->getColor() == opponentColor) {
                    oppColor++;
                }
            }
            //save the max score the opponent can get from the board state
            if (score < (oppColor - myColor)) {
                score = (oppColor - myColor);
                maxScoreRow = innerRow;
                maxScoreCol = innerCol;
            }
            delete tempInnerBoard;
            delete tempInnerLogic;
        }
        // save the min score of the opponent can get from all player possible moves
        if (minOppScore > score) {
            minOppScore = score;
            chosenRow = maxScoreRow;
            chosenCol = maxScoreCol;
        }
        delete tempBoard;
        delete tempLogic;
    }
    //the minimax strategy decision
        logic->executeOrder66(chosenRow, chosenCol);
}
