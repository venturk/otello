/*
 * Kfir Ventura
 * Avihay Arzuan
 */

#include "MainMenu.h"

MainMenu::MainMenu() {
}

MainMenu::~MainMenu() {
}

bool MainMenu::checkUserChoice(int &choice) {
    if (choice != humanPlayer && choice != computerPlayer) {
        cout << "Wrong choice! Please try again!" << endl;
        return true;
    }
    return false;
}

void MainMenu::printUserChoice(int &choice) {
    cout << "You chose to play with";
    if (choice == humanPlayer)
        cout << " human ";
    else
        cout << " computer ";
    cout << "player!" << endl << endl;
}

userChoice MainMenu::run() {
    cout << "Choose game mode:" << endl;
    cout << "Press " << humanPlayer << " for human player ";
    cout << "and " << computerPlayer << " for computer player." << endl;

    int choice = humanPlayer;
    do {
        cin >> choice;
    } while (checkUserChoice(choice));

    printUserChoice(choice);

    return (userChoice) choice;
}
