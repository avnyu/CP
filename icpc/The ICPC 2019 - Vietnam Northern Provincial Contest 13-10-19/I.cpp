#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll>p(20);

void init() {
	p[1] = 1LL;
	for (int i = 2; i < 20; ++i)p[i] = p[i - 1] * 10;
	p[17] = p[16] + 1;
}

ll get_to_rm(ll l, ll r, ll rm, ll w) {
	ll num = r - l;
	ll cnt = num / w * rm;
	if (num % w == 0)return cnt;

	l = l % w;
	r = r % w;

	if (l < r) {
		if (rm <= l)return cnt;
		return cnt + min(r, rm) - l;
	}

	return cnt + min(rm, r) + max(0LL, rm - l);
}

ll get_rm(ll l, ll r, ll rm, ll w) {
	return get_to_rm(l, r, rm, w) - get_to_rm(l, r, rm - 1, w);
}

ll get_digit_to_rm(ll rm, ll w) {
	ll res = 0;
	for (int i = 1; i < 17; ++i)
		res += get_to_rm(p[i], p[i + 1], rm, w) * i;
	return res;
}

void solve() {
	ll w, k;
	cin >> w >> k;

	ll l = 1, r = w;
	ll digits, rm, m, d, res, pos;
	while (l <= r) {
		m = (l + r) >> 1;

		d = get_digit_to_rm(m, w);
		if (d >= k) {
			rm = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}

	digits = get_digit_to_rm(rm - 1, w);

	//cout << rm << ' ' << digits << '\n';

	for (int i = 1; i < 17; ++i) {
		ll d = digits + get_rm(p[i], p[i + 1], rm, w) * i;

		if (d >= k) {
			l = p[i], r = p[i + 1] - 1;

			//cout << digits << ' ' << d << ' ' << k << ' ' << rm << ' ' << i << '\n';
			while (l <= r) {
				m = (l + r) >> 1;

				d = digits + get_rm(p[i], m + 1, rm, w) * i;
				if (d >= k) {
					res = m;
					pos = (d - k);
					r = m - 1;
				}
				else
					l = m + 1;
			}


			break;
		}

		digits = d;
	}

	//cout << res << ' ' << pos << '\n';
	while (pos--)
		res /= 10LL;

	cout << res % 10LL << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in", "r", stdin);

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}