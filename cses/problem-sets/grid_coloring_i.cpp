#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string grid[n];
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    bool used[4] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int k = grid[i][j] - 'A';
            used[k] = true;
            if (i - 1 >= 0) {
                k = grid[i - 1][j] - 'A';
                used[k] = true;
            }
            if (j - 1 >= 0) {
                k = grid[i][j - 1] - 'A';
                used[k] = true;
            }
            int l = 0;
            while (used[l]) l++; 
            grid[i][j] = 'A' + l;
            for (int l = 0; l < 4; l++) used[l] = false;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << grid[i] << "\n";
    }
    return 0;
}
