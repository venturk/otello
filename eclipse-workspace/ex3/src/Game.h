/*
* Kfir Ventura
* 301754370
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
  Game();
  void run();
  ~Game();
 private:
  Board *board;
  Player *whitePlayer, *blackPlayer, *currentPlayer;
  GameLogic *logic;
  ConsoleMsgs *printer;
  MainMenu *menu;

  char currentColor;

  int noPosMoves, numOfEmptyCells;

  void playOneTurn();
  void updateCurrentPlayer();
  bool isCurrentWhite() const;
  void updateToBlack();
  void updateToWhite();

  bool shouldRun;

  int getScore(char color) const;
  void printWinner() const;
};

#endif //EX2_GAME_H
