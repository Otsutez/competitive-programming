#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;
    ll sum = 0;
    for (ll b = 1; b <= n; b++) {
        sum += pow((n / b), 2);
    }
    cout << sum << "\n";
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
