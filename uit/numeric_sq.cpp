#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	ll ans = 1LL * (n + 1) * n / 2;
	if (ans & 1) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	ans >>= 1;
	vector<bool>a(n + 1, false);
	for (int i = n; i; --i) {
		if (ans >= i) {
			a[i] = true;
			ans -= i;
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << (a[i] ? '-' : '+');
	cout << '\n';

	return 0;
}