#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} }; 
char currentMarker;
int currentPlayer;


void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
            if (j < 2) cout << "| ";
        }
        cout << "\n";
        if (i < 2) cout << "--|---|--\n";
    }
    cout << "\n";
}


bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

  
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}


bool checkWin() {
    
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }

    
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || 
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }

    return false;
}


void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
}


void playGame() {
    cout << "Player 1, Enter your choice (X or O): ";
    cin >> currentMarker;
    currentPlayer = 1;

    displayBoard();

    int turns = 0;
    while (turns < 9) {
        int slot;
        cout << "Player " << currentPlayer << "'s turn. Enter your slot (1-9): ";
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Please choose a slot between 1 and 9.\n";
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already taken! Try again.\n";
            continue;
        }

        displayBoard();
        turns++;

        if (checkWin()) {
            cout << "Player " << currentPlayer << " wins!\n";
            return;
        }

        switchPlayer();
    }

    cout << "It's a tie!\n";
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    playGame();
    return 0;
}
