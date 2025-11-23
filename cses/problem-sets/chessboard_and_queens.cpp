#include <bits/stdc++.h>
using namespace std;

// Algorithm design:
// Use Backtracking
//
// Time complexity:
// n = 64, O(n^4)
// 8^8 computations, should be doable in 1 second

void print_board(int (&board)[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int count(int i, int (&board)[8][8]) {
    if (i == 8) {
        return 1;
    }

    int c = 0;
    for (int j = 0; j < 8; j++) {
        if (board[i][j] != 0) {
            continue;
        }

        for (int a = 1; a < 8 - i; a++) {
            if (board[i + a][j] == 0) board[i + a][j] = i + 1;
            if (j + a < 8 && board[i + a][j + a] == 0) board[i + a][j + a] = i + 1;
            if (j - a >= 0 && board[i + a][j - a] == 0) board[i + a][j - a] = i + 1;
        }
        c += count(i + 1, board);

        for (int a = 1; a < 8 - i; a++) {
            if (board[i + a][j] == i + 1) board[i + a][j] = 0;
            if (j + a < 8 && board[i + a][j + a] == i + 1) board[i + a][j + a] = 0;
            if (j - a >= 0 && board[i + a][j - a] == i + 1) board[i + a][j - a] = 0;
        }
    }
    return c;
}

int main() {
    int board[8][8] = {};

    string row;
    for (int i = 0; i < 8; i++) {
        cin >> row;
        for (int j = 0; j < row.size(); j++) {
            if (row[j] == '*') {
                board[i][j] = 9;
            }
        }
    }

    cout << count(0, board) << '\n';
}
