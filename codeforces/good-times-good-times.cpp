#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int count_digits(int x) {
	int count = 0;
	while (x > 0) {
		count++;
		x = x / 10;
	}
	return count;
}

void solve() {
    int x;
    cin >> x;
    int d = count_digits(x);
    int y = (int) pow(10, d) + 1;
    cout << y << '\n';
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
