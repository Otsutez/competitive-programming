#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int mod = 998244353;

static int qpow(int x,int y) {
    int res=1;
    while(y)
    {
        if(y&1)res=1ll*res*x%mod;
        x=1ll*x*x%mod;
        y>>=1;
    }
    return res;
}

void solve() {
    ll n, m, r, c;
    cin >> n >> m >> r >> c;
	ll ans = qpow(2,(1ll*n*(c-1)+1ll*m*(r-1)-1ll*(c-1)*(r-1))%(mod-1));
	cout << ans << '\n';
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
