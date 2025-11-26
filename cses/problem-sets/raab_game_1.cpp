#include <bits/stdc++.h>
using namespace std;

int main () {
    int t, n, a, b;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> a >> b;
        if ((a + b) > n) {
            cout << "NO\n";
            continue;
        }
        if ((a != 0 && b == 0) || (a == 0 && b != 0)) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int d = n - (a + b);
        int sz = n - d;
        int st = sz - a + 1;
        for (int i = st; i < sz + 1; i++) {
            cout << i << " ";
        }
        for (int i = 1; i < st; i++) {
            cout << i << " ";
        }
        for (int i = sz + 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << "\n";
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
