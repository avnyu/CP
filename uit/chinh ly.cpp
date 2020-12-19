#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll a, b, c;
	cin >> a >> b >> c;

	if (a / c == b / c) {
		cout << (b - a + 1) / 2 << '\n';
		return 0;
	}

	ll x = a / c + 1, y = b / c;
	ll l = (x * c - a) / 2;
	ll r = (b - y * c) / 2;
	ll ct = (y - x) * ((c - 1) / 2);
	//cout << x << ' ' << y << '\n';
	//cout << l << ' ' << r << ' ' << ct << '\n';
	cout << l + r + ct + y - x + 1 << '\n';

	return 0;
}