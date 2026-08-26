#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // set forward direction
    for (int i = 2; i < s.size(); i++) {
    	if (s[i] == '?') {
    		if (s[i - 2] != '?') {
    			s[i] = s[i - 2] == '1' ? '0' : '1';
    		}
    	} else if (s[i] == s[i - 2]) {
    		cout << 0 << '\n';
    		return;
    	}
    }

    // set backward direction
    for (int i = (int)s.size() - 3; i >= 0; i--) {
		if (s[i] == '?') {
    		if (s[i + 2] != '?') {
    			s[i] = s[i + 2] == '1' ? '0' : '1';
    		}
		} else if (s[i] == s[i + 2]) {
			cout << 0 << '\n';
			return;
		}
    }

    // Here we have either alternating ?, full ?, or no ?. If alternating there's only 2 ways, if full ? theres 4 ways and if no ? there's 1 way
    ll count = 0;
    for (int i = 0; i < s.size(); i++) {
    	if (s[i] == '?') {
    		count++;
    	}
    }

    // cout << "After pass: " << s << '\n';
    if (count == 0) {
    	cout << "1\n";
    } else if (count == s.size()) {
    	cout << "4\n";
    } else {
    	cout << "2\n";
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
