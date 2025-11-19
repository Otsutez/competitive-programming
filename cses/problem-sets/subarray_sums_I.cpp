#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, x;
    cin >> n >> x;

    ll ps = 0;
    ll count = 0;
    set<ll> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ps += a;
        if (ps == x) {
            count++;
        } else if (s.count(ps - x)) {
            count++;
        }
        s.insert(ps);
    }
    cout << count << "\n";
}
