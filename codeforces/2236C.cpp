#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int a, b, x; 
	cin >> a >> b >> x;

	int count = 0;
	while (a != b) {
		if (b < a) {
			int tmp = b;
			b = a;
			a = tmp;
		}

		int c = b - a;
		int d = abs((b / x) - a) + 1;
		int e = abs((b / x) - (a / x)) + 2;

		if (c <= d) {
			if (c <= e) {
				count += c;
				break;
			} else {
				count += 2;
				b = b / x;
				a = a / x;
			}
		} else {
			if (d <= e) {
				count += 1;
				b = b / x;
			} else {
				count += 2;
				b = b / x;
				a = a / x;
			}
		}
	}
	cout << count << '\n';
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
