#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie();

	int t;
	cin >> t;
	while (t--) {
		int n;
		ll money, add = 0;
		cin >> n >> money;
		vector<pair<int, int>>a(n);
		for (auto&i : a) {
			cin >> i.first >> i.second;
			add = add + i.first;
		}
		sort(a.begin(), a.end());

		int l = 1, r = 1e9, ans = 0;
		while (l <= r) {
			int m = (l + r) >> 1;

			int cnt = 0;
			ll sum = add;
			for (int i = n - 1; i >= 0; --i) {
				if (cnt == n / 2 + 1)break;

				if (a[i].first >= m) {
					cnt++;
					continue;
				}
				if (a[i].second >= m) {
					sum = sum + m - a[i].first;
					cnt++;
					continue;
				}
			}

			if (cnt == n / 2 + 1 && sum <= money) {
				ans = m;
				l = m + 1;
			}
			else
				r = m - 1;
		}

		cout << ans << '\n';
	}

	return 0;
}