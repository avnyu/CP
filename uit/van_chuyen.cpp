#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

	int n, h;
	cin >> n >> h;
	vector<pair<int, int>>a(n);

	for (auto&i : a) {
		cin >> i.first >> i.second;
		i.first = (i.first - h + 1 < 1 ? 1 : i.first - h + 1);
	}

	int l = 1, r = 1e9, hr = 1;
	while (l <= r) {
		int m = (l + r) >> 1;
		
		bool chk = false;
		for (auto&i : a)chk |= ((i.first >= m) & (i.second >= m));

		if (chk){l = m + 1; hr = m;}
		else r = m - 1;
	}

	ll ans = 0;
	for (auto&i : a) {
		ans = ans + (i.second - hr > 0 ? i.second - hr : 0);
	}

	cout << ans << '\n';

	return 0;
}