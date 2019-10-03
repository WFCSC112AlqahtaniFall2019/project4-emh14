/* Class: TicTacToe
 * Author: [FINISH ME]
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
using namespace std;

int main() {
    //Welcome
    cout << "Let's play Tic-Tac-Toe!" << endl << endl;

    //Creates and prints clean board
    TicTacToe newGame;
    newGame.initializeBoard();
    newGame.printBoard();

    //Prompt for input
    cout << endl << endl << "Enter Row and Column: " << endl;
    int chooseRow;
    int chooseCol;

    //Player enters choices
    cin >> chooseRow;
    cin >> chooseCol;

    //Check to make sure input is within range
    while (chooseRow < 1 || chooseRow > 3 || chooseCol < 1 || chooseCol > 3) {
        cout << "Error! Invalid entry, guess again" << endl << "Enter Row and Column: " << endl;
        cin >> chooseRow;
        cin >> chooseCol;
    }

    // Scales input so user can enter numbers 1-3
    chooseRow--;
    chooseCol--;

    //Update and print game board
    newGame.placeMark(chooseRow, chooseCol);
    newGame.printBoard();

    return 0;
}