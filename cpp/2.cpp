#include <iostream>
using namespace std;
class GobangBoard {
public:
    GobangBoard() {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 19; j++) {
                board[i][j] = 0;
            }
        }
        currentPlayer = 1;
    }
    void makeMove(int row, int col) {
        if (board[row][col] != 0) {
            cout << "Invalid move!" << endl;
            return;
        }
        board[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
    int checkWin(){
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 15; j++) {
            if (board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2] && board[i][j] == board[i][j+3] && board[i][j] == board[i][j+4] && board[i][j] != 0) {
                return board[i][j];
            }
        }
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 19; j++) {
            if (board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j] && board[i][j] == board[i+3][j] && board[i][j] == board[i+4][j] && board[i][j] != 0) {
                return board[i][j];
            }
        }
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2] && board[i][j] == board[i+3][j+3] && board[i][j] == board[i+4][j+4] && board[i][j] != 0) {
                return board[i][j];
            }
        }
    }
    for (int i = 4; i < 19; i++) {
        for (int j = 0; j < 15; j++) {
            if (board[i][j] == board[i-1][j+1] && board[i][j] == board[i-2][j+2] && board[i][j] == board[i-3][j+3] && board[i][j] == board[i-4][j+4] && board[i][j] != 0) {
                return board[i][j];
            }
        }
    }
    }
    int getCurrentPlayer(){
        return currentPlayer;
    }
    char winperson(int num){
        return player[num-1];
    }
private:
    int board[19][19];
    int currentPlayer;
    string player="AB";
};
int main(){
GobangBoard board;
int row, col;
while (true) {
    if (board.getCurrentPlayer() == 1) {
        cout << "Player A: ";
        cin >> row >> col;
        board.makeMove(row, col);
    }
    else {
        cout << "Player B: ";
        cin >> row >> col;
        board.makeMove(row, col);
    }
    int winner = board.checkWin();
    if (winner != 0) {
        cout << "Player " << board.winperson(winner) << " wins!" << endl;
        break;
    }
}
}