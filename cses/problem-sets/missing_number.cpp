#include <iostream>
using namespace std;

int main() {
    using ll = long long;
    ll n;
    cin >> n;

    // Calculate target sum
    ll expected_sum = 0;
    for (int i = 1; i <= n; i++) {
        expected_sum += i;
    }

    // Calculate actual sum
    ll actual_sum = 0;
    ll x;
    while (cin >> x) {
        actual_sum += x;
    }

    // Print missing number
    cout << expected_sum - actual_sum << "\n";
}
