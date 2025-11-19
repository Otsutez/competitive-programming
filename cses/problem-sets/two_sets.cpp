#include <bits/stdc++.h>
using namespace std;

/*
1 No
2 NO
3 Yes 1 2 and 3
4 No
5 No
6 NO

7     4 3
  6 5     2 1
6     3 2
  5 4     1
10    7 6   3 2
  9 8    5 4    1
11     8 7    4 3
   10 9    6 5    2 1
*/
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> x;
    vector<ll> y;
    ll sum1 = 0;
    ll sum2 = 0;
    for (int i = n; i >= 1; i--) {
        if (sum2 < sum1) {
            y.push_back(i);
            sum2 += i;
        } else {
            x.push_back(i);
            sum1 += i;
        }
    }

    if (sum1 == sum2) {
        cout << "YES" << "\n";
        cout << x.size() << "\n";
        for (auto e : x) {
            cout << e << " ";
        }
        cout << "\n";
        cout << y.size() << "\n";
        for (auto e : y) {
            cout << e << " ";
        }
        cout << "\n";
    } else {
        cout << "NO" << "\n";
    }
}
