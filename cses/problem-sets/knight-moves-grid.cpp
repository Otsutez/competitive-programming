#include <bits/stdc++.h>
using namespace std;

struct coord {
    int x;
    int y;
    int move;
};

int main() {
    int n;
    cin >> n;
    int board[n][n];
    int added[n][n] = {}; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = -1;
        }
    }
    // Use queue, BFS not DFS
    queue<struct coord> q = {};
    q.push(coord {0, 0, 0});
    added[0][0] = 1;

    while (!q.empty()) {
        struct coord curr = q.front();
        q.pop();
        board[curr.y][curr.x] = curr.move;

        int v[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int h[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; k++) {
            int y = curr.y + v[k];
            int x = curr.x + h[k];
            if (y >= 0 && y < n && x >=0 && x < n && !added[x][y]) {
                q.push(coord {x, y, curr.move + 1});
                added[x][y] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
