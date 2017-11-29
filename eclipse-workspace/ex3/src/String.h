/*
 * Kfir Ventura
 * Avihay Arzuan
 */

#ifndef EX2_STRING_H
#define EX2_STRING_H

#include <string>
#include <cstdio>

using namespace std;

class String {
 public:
  /**
   * The method converts two int values into a string point format "(x,y)".
   * @param x - x coordinate
   * @param y - y coordinate
   * @return "(x,y)"
   */
  static string intToPoint(int x, int y);
};

#endif //EX2_STRING_H
