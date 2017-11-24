/*
 * MainMenu.h
 *
 *  Created on: Nov 24, 2017
 *      Author: avihay
 */

#ifndef MAINMENU_H_
#define MAINMENU_H_
#include <iostream>

using namespace std;

typedef enum userChoice {
    humanPlayer, computerPlayer
} userChoice;

/*
 *
 */
class MainMenu {
 public:
    MainMenu();
    virtual ~MainMenu();
    userChoice run();
 private:
    bool checkUserChoice(int &choice);
    void printUserChoice(int &choice);
};

#endif /* MAINMENU_H_ */
