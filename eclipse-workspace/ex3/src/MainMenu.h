/*
 * Kfir Ventura
 * Avihay Arzuan
 */

#ifndef MAINMENU_H_
#define MAINMENU_H_
#include <iostream>

using namespace std;

typedef enum userChoice {
    humanPlayer, computerPlayer
} userChoice;

/*
 * The class runs the main menu
 */
class MainMenu {
 public:
    //C'tor
    MainMenu();
    //D'tor
    virtual ~MainMenu();
    /**
     * asks for user choice
     * @return int the user choice
     */
    userChoice run();
 private:
    /**
     * check validation of the user
     * @param choice the user input
     * @return true if valid false otherwise
     */
    bool checkUserChoice(int &choice);
    /**
     * prints to screen the user choice
     * @param choice
     */
    void printUserChoice(int &choice);
};

#endif /* MAINMENU_H_ */
