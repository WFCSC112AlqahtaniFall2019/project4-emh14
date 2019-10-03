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

    while (!newGame.checkForWin() && !newGame.isBoardFull()) {

        //Prompt for input
        cout << endl << endl << "Player: " << newGame.getCurrentPlayerNumber() << endl << "Enter Row and Column: " << endl;
        int chooseRow;
        int chooseCol;

        //Player enters choices
        cin >> chooseRow;
        cin >> chooseCol;

        // Scales input so user can enter numbers 1-3
        chooseRow--;
        chooseCol--;

        //Check to make sure input is within range and update it if move is valid
        while (!newGame.placeMark(chooseRow, chooseCol)) {
            cout << "Error! Invalid entry, guess again" << endl << "Enter Row and Column: " << endl;
            cin >> chooseRow;
            cin >> chooseCol;

            // Scales input so user can enter numbers 1-3
            chooseRow--;
            chooseCol--;
        }




        //Print game board
        newGame.printBoard();

        //Change player
        newGame.changePlayer();
    }
    return 0;
}