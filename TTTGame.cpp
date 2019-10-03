/* Class: TicTacToe
 * Author: Ethan Harrison
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
#include <ctime>
using namespace std;

int main() {
    //Welcome
    cout << "Let's play Tic-Tac-Toe!" << endl << endl;

    //Ask if one or two player
    int numPlayers;
    cout << "One-player or Two-player (1 or 2): ";
    cin >> numPlayers;
    cout << endl;

    //Creates and prints clean board
    TicTacToe newGame;
    newGame.initializeBoard();
    newGame.printBoard();

    //Check the number of players to see if the computer will play
    if (numPlayers == 1){
        srand(time(NULL)); //seed random function by time

        //if random number generator chooses 2, then change player
        if ((rand()%2 + 1) == 1){
            newGame.changePlayer();
        }
    } else {
        //Change player to ensure Player 1 starts
        newGame.changePlayer();
    }

    while (!newGame.checkForWin() && !newGame.isBoardFull()) {

        //Change player
        newGame.changePlayer();

        //Have computer play if in single player mode and is the computer's turn
        if(numPlayers==1 && newGame.getCurrentPlayerNumber() == 2){

            //Generating computer's choice
            cout << endl << endl << "Computer: " << endl;
            int chooseRow = rand()%3;
            int chooseCol = rand()%3;

            //Check to make sure input is within range and update it if move is valid
            while (!newGame.placeMark(chooseRow, chooseCol)) {
                chooseRow = rand()%3;
                chooseCol = rand()%3;
            }
        }

        //Humans turn against computer or Two person play
        else {

            //Prompt for input
            cout << endl << endl << "Player: " << newGame.getCurrentPlayerNumber() << endl << "Enter Row and Column: ";
            int chooseRow;
            int chooseCol;

            //Player enters choices
            cin >> chooseRow;
            cin >> chooseCol;
            cout << endl;

            // Scales input so user can enter numbers 1-3
            chooseRow--;
            chooseCol--;

            //Check to make sure input is within range and update it if move is valid
            while (!newGame.placeMark(chooseRow, chooseCol)) {
                cout << "Error! Invalid entry, guess again" << endl << "Enter Row and Column: ";
                cin >> chooseRow;
                cin >> chooseCol;
                cout << endl;

                // Scales input so user can enter numbers 1-3
                chooseRow--;
                chooseCol--;
            }
        }
        //Print game board
        newGame.printBoard();
    }

    //Print results of game
    if (newGame.checkForWin()){
        if (numPlayers==1 && newGame.getCurrentPlayerNumber() == 2) {
            cout << "Computer wins!" << endl;
        } else {
            cout << "Player " << newGame.getCurrentPlayerNumber() << " wins!" << endl;
        }
    }
    else{
        cout << "It is a draw!" << endl;
    }

    return 0;
}