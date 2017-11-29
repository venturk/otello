/*
 * Kfir Ventura
 * Avihay Arzuan
 */
#include "String.h"

string String::intToPoint(int x, int y) {
  char rowString[4], colString[4];
  string str = "";

  sprintf(rowString, "%d", x);
  sprintf(colString, "%d", y);

  return str + '(' + rowString + ',' + colString + ')';
}
