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
    MiniMaxLogic::useMiniMaxMove(logic, posMoves);
}
