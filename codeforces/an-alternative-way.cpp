#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);

    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
	}

	ll leftover = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (b[i] >= a[i]) {
			if (leftover > 0) {
				leftover -= (b[i] - a[i]);
				leftover = max(0ll, leftover);
			}
		} else {
			leftover += (a[i] - b[i]);
		}
	}

	if (leftover == 0) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main()
{
#ifdef FELIX
	auto _clock_start = chrono::high_resolution_clock::now();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	int tests = 1;
	cin >> tests;
	while(tests--){
		solve();
	}
 
#ifdef FELIX
	cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
		chrono::high_resolution_clock::now()
			- _clock_start).count() << "ms." << endl;
#endif
	return 0;
}
