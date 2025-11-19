#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    vector<string> v;

    cin >> s;
    sort(s.begin(), s.end());
    v.push_back(s);

    while (next_permutation(s.begin(), s.end())) {
        v.push_back(s);
    }

    cout << v.size() << '\n';
    for (auto e : v) {
        cout << e << '\n';
    }
    return 0;
}
