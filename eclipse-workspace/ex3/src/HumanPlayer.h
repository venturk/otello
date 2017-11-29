/*
 * Kfir Ventura
 * Avihay Arzuan
 */
#ifndef EX2_HUMANPLAYER_H
#define EX2_HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
 public:
  /**
   * Constructor.
   * @param color - player's color.
   */
  HumanPlayer(char color);
  /**
   * @return player's color.
   */
  virtual char getColor() const;

  /**
   * Destructor.
   */
  virtual ~HumanPlayer() {};

  /**
   * The method asks user's choice and responsible to execute it.
   * @param logic - rules of the game.
   * @param posMoves - the possible moves to choose from.
   * @param printer - the console printer.
   */
  void makeMove(GameLogic *logic, map<string,Cell> &posMoves, ConsoleMsgs printer);
 private:
  /**
   * Members.
   */
  const char color;
};

#endif //EX2_HUMANPLAYER_H
