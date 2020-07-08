#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("input", "r", stdin);

	int n;
	cin >> n;
	vector<int>a(n);
	vector<ll>b(n + 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i + 1] = b[i] + a[i];
	}
	vector<int>c(a.begin(), a.end());
	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());
	vector<vector<int>>pos(c.size());
	for (int i = 0; i < n; ++i)
		pos[lower_bound(c.begin(), c.end(), a[i]) - c.begin()].push_back(i);

	ll ans = 0, l, r;
	for (auto&i : pos) {
		ll s = -1e9 - 1, ln;
		for (int j = 1; j < i.size(); ++j) {
			if (s < a[i[j - 1]]) {
				s = a[i[j - 1]];
				ln = i[j - 1] + 1;
			}
			s += b[i[j] + 1] - b[i[j - 1] + 1];
			if (ans < s) {
				ans = s;
				l = ln;
				r = i[j] + 1;
			}
		}
	}

	cout << ans << '\n' << l << ' ' << r << '\n';

	return 0;
}