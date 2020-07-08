#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int l, r, a;
	cin >> l >> r >> a;

	if (l > r - a) {
		cout << 0;
		return 0;
	}

	int k = (r - l) / a;
	ll ans = 0;
	ans = 1LL * a * (k - 1) * k / 2;
	ans += 1LL * ((r - l) % a + 1) * k;

	cout << ans << '\n';


	return 0;
}