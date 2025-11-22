#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// This solution fails because C can be very large resulting in a very large
// array. Not enough memory.

void dynamic_programming() {
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

int main() {
    int n;
    cin >> n;

    ll apples[n];
    for (int i = 0; i < n; i++) {
        cin >> apples[i];
    }

    ll min_diff = numeric_limits<ll>::max();
    // cout << min_diff << "\n";

    // Use gray code to generate all possible subset for one group. Leftover
    // apples go to the other group
    for (int i = 0; i <= pow(2, n); i++) {
        int code = i ^ (i >> 1);
        ll first_group = 0;
        ll second_group = 0;
        for (int j = 0; j < n; j++) {
            int mask = 1 << (n - (j + 1));
            if (code & mask) {
                first_group += apples[j];
            } else {
                second_group += apples[j];
            }
        }
        min_diff = min(min_diff, abs(first_group - second_group));
    }
    cout << min_diff << "\n";

    return 0;
}
