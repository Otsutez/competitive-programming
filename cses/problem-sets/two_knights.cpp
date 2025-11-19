#include <bits/stdc++.h>
using namespace std;

/*
k = 1: 0
k = 2: 6
k = 3: 28

Total possible positions = k*k C 2
Algorithm:
1. Calculate total number of positions
2. Go through each tile, calculate number of positions that 2 knight
can be placed and will land at that tile, subtract from total position.
*/
long long choose2(long long n) {
    return n * (n - 1) / 2;
}

long long calc(long long k) {
    long long s = choose2(k*k);
    s = s - 4 * (k - 1) * (k - 2);
    return s;
}

int main() {
    int n;
    cin >> n;

    for (int k = 1; k <= n; k++) {
        long long res = calc((long long)k);
        cout << res << "\n";
    }
}
