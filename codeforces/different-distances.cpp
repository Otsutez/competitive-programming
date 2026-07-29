#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string evenPattern = "12212112";
    string threePattern = "112123132233";
    if (n % 2 == 0) {
    	for (int i = 1; i < n; i += 2) {
    		for (auto c : evenPattern) {
    			if (c == '1') {
    				cout << i << ' ';
    			} else {
    				cout << i + 1 << ' ';
    			}
    		}
    	}
    } else {
    	for (auto c : threePattern) {
    		cout << c << ' ';
    	}
    	for (int i = 4; i < n; i += 2) {
    		for (auto c : evenPattern) {
    			if (c == '1') {
    				cout << i << ' ';
    			} else {
    				cout << i + 1 << ' ';
    			}
    		}
    	}
    }
	cout << '\n';
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
