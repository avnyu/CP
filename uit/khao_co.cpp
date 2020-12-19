#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n, t;
	cin >> n >> t;
	vector<ll>h(n);
	for (auto&i : h)cin >> i;

	ll l = -1e9, r = 1e9, ans = 1e9, cost;
	while (l <= r) {
		ll m = (l + r) >> 1LL;

		ll il = 0, ir = 0;
		ll s = 0, c;
		bool chk = false;

		for (ll i = 0; i < n; ++i) {
			s += ir + il - i - i;

			c = m + ir - i;
			ir = max(i, ir);
			while (ir < n && h[ir] > c) {
				s += h[ir] - c;
				ir++;
				c++;
			}

			c = m + i - il;
			while (il < i && h[il] < c) {
				s += c - h[il];
				il++;
				c--;
			}

			if (s <= t) {
				chk = true;
				break;
			}
		}

		if (chk) {
			ans = m;
			cost = s;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	t -= cost;

	if (ans == int(-1e9)) {
		ans -= t / n;
	}

	cout << ans << '\n';

	return 0;
}