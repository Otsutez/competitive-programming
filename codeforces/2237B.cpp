#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, i;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<bool> selected(n);
    selected = {false};
    for (i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (i = 0; i < n; i++) {
    	cin >> b[i];
    }

    bool valid = true;
    for (i = 0; i < n; i++) {
    	bool found = false;
    	for (int j = 0; j < n; j++) {
    		if (a[j] <= b[i] && !selected[j]) {
    			a[j] = b[i];
    			selected[j] = true;
    			found = true;
    			break;
    		}
    	}
    	if (!found) {
    		valid = false;
    		break;
    	}
    }

    if (valid) {
    	// Count inversions
    	int count = 0;
    	for (i = 0; i < n; i++) {
    		for (int j = i + 1; j < n; j++) {
    			if (a[i] > a[j]) {
    				count++;
    			}
    		}
    	}
    	cout << count << '\n';
    } else {
    	cout << -1 << '\n';
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
