#include <bits/stdc++.h>
using namespace std;

/*
This solution fails because C can be very large resulting in a very large array. Not enough memory.
*/

int main() {
    /* Get inputs */
    int n;
    cin >> n;

    int apples[n];
    int t = 0;

    for (int i = 0; i < n; i++) {
        cin >> apples[i];
        t += apples[i];
    }

    /* 0-1 Knapsack for capacity t/2 */
    int c = t / 2;
    int dp[c + 1][n + 1];

    for (int i = 0; i < c + 1; i++) {
        dp[i][0] = 0;
    }
    for (int k = 0; k < n + 1; k++) {
        dp[0][k] = 0;
    }

    for (int k = 1; k < n + 1; k++) {
        for (int i = 1; i < c + 1; i++) {
            if (i < apples[k - 1]) {
                dp[i][k] = dp[i][k - 1];
            } else {
                int wk = apples[k - 1];
                dp[i][k] = max(wk + dp[i - wk][k - 1], dp[i][k - 1]);
            }
        }
    }

    cout << t - 2 * dp[c][n] << "\n";
}
