/*
 * Kfir Ventura
 * Avihay Arzuan
 */

#include "MiniMaxAlgo.h"
#include "iostream"
#define HIGHNUM 1000
#define LOWNUM -1000
#define STARTNUM 0

void MiniMaxAlgo::useMiniMaxMove(GameLogic *logic, map<string, Cell> posMoves,
                                 char color, char opponentColor,
                                 Board * board) {
    int chosenRow = STARTNUM, chosenCol = STARTNUM, maxScoreRow = STARTNUM,
            maxScoreCol = STARTNUM;
    int minOppScore = HIGHNUM, score = LOWNUM;
    //iterates each possible move of the player
    for (Iterator it = posMoves.begin(); it != posMoves.end(); it++) {
        Board *tempBoard = new Board(*board);
        DefaultLogic * t = static_cast<DefaultLogic *>(logic);
        DefaultLogic *tempLogic = new DefaultLogic(*t);
        int row, col;
        row = it->second.getRow();
        col = it->second.getCol();
        //make the possible move
        if (posMoves.count(String::intToPoint(row, col))) {
            tempLogic->executeOrder66(row, col);
            map<string, Cell> m = tempLogic->getPossibleMoves(opponentColor);
            map<string, Cell> tempPosMoves(m);
            // iterates the opponent moves after making one of the possible moves
            for (Iterator innerIt = tempPosMoves.begin();
                    innerIt != tempPosMoves.end(); innerIt++) {
                Board* tempInnerBoard = new Board(*tempBoard);
                DefaultLogic *d = static_cast<DefaultLogic *>(tempLogic);
                DefaultLogic *tempInnerLogic = new DefaultLogic(*d);
                int innerRow = innerIt->second.getRow();
                int innerCol = innerIt->second.getCol();
                //make one of the opponent move
                if (tempPosMoves.count(
                        String::intToPoint(innerRow, innerCol))) {
                    tempInnerLogic->executeOrder66(innerRow, innerCol);
                    map<string, Cell> m2 = *tempInnerBoard->getCellsList();
                    map<string, Cell> cells(m2);
                    int myColor = STARTNUM, oppColor = STARTNUM;
                    //counts the difference
                    for (Iterator i = cells.begin(); i != cells.end(); i++) {
                        if (i->second.getColor() == color) {
                            myColor++;
                        } else if (i->second.getColor() == opponentColor) {
                            oppColor++;
                        }
                    }
                    //save the max score the opponent can get from the board state
                    if (score < (oppColor - myColor)) {
                        score = (oppColor - myColor);
                        maxScoreRow = row;
                        maxScoreCol = col;
                    }
                }
                delete tempInnerBoard;
                tempInnerBoard = 0;
                delete tempInnerLogic;
                tempInnerLogic = 0;
            }
            // save the min score of the opponent can get from all player possible moves
            if ((minOppScore > score) && (score != -1000)) {
                minOppScore = score;
                chosenRow = maxScoreRow;
                chosenCol = maxScoreCol;
            }
        }
        delete tempBoard;
        tempBoard = 0;
        delete tempLogic;
        tempLogic = 0;
    }
    //the minimax strategy decision
    logic->executeOrder66(chosenRow, chosenCol);
}
