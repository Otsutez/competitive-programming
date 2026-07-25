#include <bits/stdc++.h>
#include <limits>

using namespace std;

void print_vec(vector<int> &v) {
    for (auto e : v) cout << e << ' ';
    cout << "\n";
}

int main() {
    int t, n, j, k;
    cin >> t;
    for (j = 0; j < t; j++) {
        cin >> n;
        vector<int> a(n);
        for (k = 0; k < n; k++) {
            cin >> a[k];
        }

        vector<int> prefSum1(n);
        vector<int> prefSum2(n);
        int sum1 = 0; int sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) sum1++; else sum1--;
            if (a[i] == 3) sum2--; else sum2++;
            prefSum1[i] = sum1;
            prefSum2[i] = sum2;
        }


        int x, y;
        int found = 0;
        int minPrefSum2 = numeric_limits<int>::max();
        for (y = 0; y < n - 1; y++) {
            x = y - 1;
            if (x >= 0 && prefSum1[x] >= 0) {
                minPrefSum2 = min(minPrefSum2, prefSum2[x]);
            }
            if (prefSum2[y] >= minPrefSum2) {
                found = 1;
                break;
            }
        }
        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }

    return 0;
}
