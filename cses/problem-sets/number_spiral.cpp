#include <bits/stdc++.h>
using namespace std;

/*
Observations:
Time limit is 1s and input size can be as big as 10^14. O(n) algorithm would be too slow so we must figure out a formula to find answer in O(1) time

Lessons:
Becareful when choosing data type, calculations may overflow int, use long long. Don't use pow() for powers of 2, just multiply.
*/

int main() {
    long long t, x, y;
    cin >> t;

    for (long long i = 0; i < t; i++) {
        cin >> y >> x;
        long long res;
        if (y > x) {
            if (y % 2 == 0) {
                res = y * y - (x - 1);
            } else {
                res = (y - 1) * (y - 1) + 1 + (x - 1);
            }
        } else {
            if (x % 2 == 1) {
                res = x * x - (y - 1);
            } else {
                res = (x - 1) * (x - 1) + 1 + (y - 1);
            }
        }
        cout << res << "\n";
    }
}
