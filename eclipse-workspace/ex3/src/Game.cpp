/*
* Kfir Ventura
* 301754370
*/
#include "Game.h"

Game::Game() : noPosMoves(0), shouldRun(true) {
  this->board = new Board();
  this->whitePlayer = new HumanPlayer(WHITE);
  this->blackPlayer = new HumanPlayer(BLACK);
  this->logic = new DefaultLogic(this->board);
  this->printer = new ConsoleMsgs();
  this->menu = new MainMenu();

  this->numOfEmptyCells = (this->board->getSize() * this->board->getSize()) - 4;
  this->currentPlayer = this->blackPlayer;
  this->currentColor = this->currentPlayer->getColor();
}

void Game::run() {
  this->menu->run();

  while (this->shouldRun) {
    playOneTurn();
    this->updateCurrentPlayer();
  }
  this->printWinner();
}

void Game::printWinner() const {
  int blackScore = this->getScore(blackPlayer->getColor());
  int whiteScore = this->getScore(whitePlayer->getColor());

  if (blackScore > whiteScore)
    this->printer->printWinner(BLACK);
  else if (blackScore < whiteScore)
    this->printer->printWinner(WHITE);
  else
    this->printer->printWinner(EMPTY);
}

void Game::playOneTurn() {
  CellMap *posMoves = logic->getPossibleMoves(this->currentColor);

  this->printer->curBoard(this->board);

  if (!this->numOfEmptyCells) {
    this->shouldRun = false;
    return;
  }

  this->printer->itsYourMove(this->currentColor);

  if (posMoves->getSize()) {
    this->printer->posMoves(posMoves);
    this->printer->plsEnterMove();
    this->noPosMoves = 0;
  } else {
    this->printer->noPosMoves();
    this->noPosMoves++;

    if (this->noPosMoves == 2)
      this->shouldRun = false;

    return;
  }

  currentPlayer->makeMove(this->logic, posMoves, this->printer);

  this->numOfEmptyCells--;
}

void Game::updateCurrentPlayer() {
  if (isCurrentWhite())
    this->updateToBlack();
  else
    this->updateToWhite();

  this->currentColor = this->currentPlayer->getColor();
}

bool Game::isCurrentWhite() const {
  return (this->currentColor == WHITE);
}

void Game::updateToBlack() {
  this->currentPlayer = this->blackPlayer;
}

void Game::updateToWhite() {
  this->currentPlayer = this->whitePlayer;
}

int Game::getScore(char color) const {
  int score = 0;

  for (Iterator iterator = this->board->getCellsList()->begin();
       iterator != this->board->getCellsList()->end(); iterator++)
    if (iterator->second->isFilledWith(color))
      score++;

  return score;
}

Game::~Game() {
  delete this->board;
  delete this->printer;
  delete this->blackPlayer;
  delete this->whitePlayer;
  delete this->logic;
  delete this->menu;
}
