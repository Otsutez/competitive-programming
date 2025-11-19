#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> array (n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    long long move = 0;
    for (int i = 1; i < n; i++) {
        if (array[i] < array[i - 1]) {
            int diff = array[i - 1] - array[i];
            array[i] += diff;
            move += diff;
        }
    }
    cout << move << "\n";
}
