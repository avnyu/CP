#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
	int n, l, w;
	ll res = 0;
	cin >> n;
	vector<pair<int, int>>a(n);
	for (int i = 0; i < n; ++i) {
		cin >> l >> w;
		if (l > w)swap(l, w);
		a[i] = {l, w};

		res = max(res, 1LL * l * w);
	}
	sort(a.begin(), a.end());

	priority_queue<int>q;
	q.push(a[n - 1].second);

	for (int i = n - 2; i >= 0; --i) {
		q.push(a[i].second);

		l = q.top();
		q.pop();
		w = q.top();
		q.push(l);

		res = max(res, 2LL * w * a[i].first);
	}

	cout << res / 2 << (res & 1 ? ".5\n" : ".0\n");
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	solve();

	return 0;
}