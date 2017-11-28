/*
* Kfir Ventura
* 301754370
*/
#include "String.h"
#include <vector>

string String::intToPoint(int x, int y) {
  char rowString[4], colString[4];
  string str = "";

  sprintf(rowString, "%d", x);
  sprintf(colString, "%d", y);

  return str + '(' + rowString + ',' + colString + ')';
}

//string String::stringToRow(string str) {
//
//}
//
//string String::stringToCol(string str) {
//
//}
