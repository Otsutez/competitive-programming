#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int longest = 0;
    int curLength = 0;
    for (auto c : s) {
    	if (c == '#') {
    		curLength++;
    	} else {
    		longest = max(curLength, longest);
    		curLength = 0;
    	}
    }
	longest = max(curLength, longest);
    cout << (longest + 2 - 1) / 2 << '\n';
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
