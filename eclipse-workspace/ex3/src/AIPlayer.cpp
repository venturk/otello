/*
 * AIPlayer.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author: avihay
 */

#include "AIPlayer.h"

AIPlayer::AIPlayer(char color)
        : color(color) {

}


char AIPlayer::getColor() const {
    return this->color;
}

void AIPlayer::makeMove(GameLogic *logic, CellMap *posMoves,
                        ConsoleMsgs *printer) {
    char oppColor;
    if (this->color == BLACK) {
        oppColor = WHITE;
    } else {
        oppColor = BLACK;
    }
    MiniMaxAlgo::useMiniMaxMove(logic, posMoves, this->color,oppColor, );
}
