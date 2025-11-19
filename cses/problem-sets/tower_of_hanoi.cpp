#include <bits/stdc++.h>
using namespace std;

void moves(int x, int y, int z, int n) {
    if (n == 1) {
        cout << x << " " << z << "\n";
        return;
    }

    moves(x, z, y, n - 1);
    cout << x << " " << z << "\n";
    moves(y, x, z, n - 1);

}

int main() {
    int n;
    cin >> n;

    // Find minimum moves by using Dynamic Programming
    int dp[n];
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] * 2 + 1;
    }

    cout << dp[n - 1] << "\n";
    moves(1, 2, 3, n);

    return 0;
}

