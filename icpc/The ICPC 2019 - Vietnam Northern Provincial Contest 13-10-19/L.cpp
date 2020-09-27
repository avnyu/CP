#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<ll>a(n), b(n);
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = a[i] * a[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ll ans1 = 0, ans2 = 0, ans3 = 0;
	for (ll i = 0; i < n - 1; ++i)
		for (ll j = i + 1; j < n; ++j) {
			ll x = b[i] + b[j];
			ll y = a[i] + a[j];
			ll bg = j + 1LL;

			ll lb = lower_bound(b.begin() + bg, b.end(), x) - b.begin();
			ll ub = upper_bound(b.begin() + bg, b.end(), x) - b.begin();
			ll mb = lower_bound(a.begin() + bg, a.end(), y) - a.begin();

			ans1 += lb - bg;
			ans2 += ub - lb;
			ans3 += mb - ub;
		}

	cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';

	return 0;
}