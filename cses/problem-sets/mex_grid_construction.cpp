#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int m = 2 * n;
    int grid[n][n] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool found[m] = {false};
            for (int x = j - 1; x >= 0; x--) {
                found[grid[i][x]] = true;
            }
            for (int y = i - 1; y >= 0; y--) {
                found[grid[y][j]] = true;
            }
            int k = 0;
            while (found[k]) {
                k++;
            }
            grid[i][j] = k;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
