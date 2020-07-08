#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll M = 1e9 + 7;

ll pow(ll x, ll y) {
	ll res = 1LL;
	while (y) {
		if (y & 1LL)res = (res * x) % M;
		y >>= 1LL;
		x = (x * x) % M;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n, m;
	cin >> n >> m;
	cout << pow(pow(2LL, m) - 1LL, n) << '\n';

	return 0;
}