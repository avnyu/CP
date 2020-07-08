#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<long long>p3(40, 1);
vector<long long>p2(40, 1);

void init() {
	for (int i = 1; i < 40; ++i) {
		p3[i] = p3[i - 1] * 3;
		p2[i] = p2[i - 1] * 2;
	}
}

long long good_num(long long n) {
	long long res = 0;

	for (int i = 40; i >= 0; --i)
		if (n >= p2[i]) {
			res += p3[i];
			n -= p2[i];
		}

	return res;
}

int main() {

	init();

	int q;
	cin >> q;

	while (q--) {

		long long n;
		cin >> n;
		ll res = 5e18;

		ll l = 0, r = (1LL << 40LL) - 1LL;

		while (l <= r) {
			ll m = (l + r) >> 1LL;

			ll x = good_num(m);
			//cout << m << ' ' << x << '\n';

			if (x >= n) {
				res = min(res, x);
				r = m - 1;
			}
			else
				l = m + 1;
		}
		
		cout << res << '\n';
	}

	return 0;
}