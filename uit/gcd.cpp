#include <bits/stdc++.h>
#define ll long long
using namespace std;


const ll N = 4e6 + 7;
ll it[N], n, k;

ll up(ll p, ll val, ll i = 1, ll l = 0, ll r = k - 1){
	if ( p < l || p > r ) return it[i];
	if ( l == r ) return it[i] = val;

	ll m = (l + r) >> 1;
	return it[i] = __gcd(up(p, val, i + i, l, m), up(p, val, i + i + 1, m + 1, r));
}

int main(){
	cin >> n >> k;
	vector<ll>a(n);
	for ( auto &i:a ) cin >> i;

	for ( ll i = 0; i < k; ++i ) up(i, a[i]);

	ll ans = it[1];
	for ( ll i = k; i < n; ++i ) {
		up(i % k, a[i]);
		ans = max(ans, it[1]);
	}
	cout << ans;
	return 0;
}