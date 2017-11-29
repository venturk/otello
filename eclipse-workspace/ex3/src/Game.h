/*
 * Kfir Ventura
 * Avihay Arzuan
 */
#ifndef EX2_GAME_H
#define EX2_GAME_H

#include "Board.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "DefaultLogic.h"
#include "ConsoleMsgs.h"
#include "MainMenu.h"
#include <iostream>

using namespace std;

class Game {
 public:
    //c'tor
    Game();
    /**
     * the method runs the game
     */
    void run();
    //d'tor
    ~Game();
 private:
    Board b;
    Board *board;
    Player *whitePlayer, *blackPlayer, *currentPlayer;
    GameLogic *logic;
    ConsoleMsgs printer;
    MainMenu menu;
    char currentColor;
    int noPosMoves, numOfEmptyCells;
    /**
     * one of the players play one turn
     */
    void playOneTurn();
    /**
     * update the curent player playing
     */
    void updateCurrentPlayer();
    /**
     *
     * @return if the player playing is the white player
     */
    bool isCurrentWhite() const;
    /**
     * update the current player
     */
    void updateToBlack();
    /**
     * update the current player
     */
    void updateToWhite();
    /**
     * check if the game should keep running
     */
    bool shouldRun;
    /**
     * @param color the color to count
     * @return the score value
     */
    int getScore(char color) const;
    /**
     * prints the winner to screen
     * if there any.
     */
    void printWinner() const;
};

#endif //EX2_GAME_H
