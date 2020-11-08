#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
	int n, m, p, t, i;
	ll e;
	cin >> n >> m;

	vector<ll>dp(m + 1, -1);
	vector<vector<int>>a(m + 1, vector<int>(3));
	priority_queue<tuple<int, int, int, ll>>q;

	for (int i = 1; i <= m; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		q.push(make_tuple(-a[i][0], 0, i, 0LL));
		q.push(make_tuple(-a[i][1], 1, i, 0LL));
	}

	dp[0] = 0;
	while (!q.empty()) {
		tie(p, t, i, e) = q.top();
		q.pop();

		if (t == 2) {
			dp[i] = max(dp[i], e);
			if (i) q.push(make_tuple(-a[i][1], 2, 0, e));
		}
		else if (t == 1)
			dp[i] = -1;
		else {
			q.push(make_tuple(-a[i][1], 2, 0, dp[0] + a[i][2]));
			for (int v = 1; v <= m; ++v) {
				if (dp[v] == -1 || i == v)continue;
				if (a[i][1] == a[v][1])q.push(make_tuple(-a[i][1], 2, 0, dp[v] + a[i][2]));
				if (a[i][1] < a[v][1])q.push(make_tuple(-a[i][1], 2, v, dp[v] + a[i][2]));
				if (a[i][1] > a[v][1])q.push(make_tuple(-a[v][1], 2, i, dp[v] + a[i][2]));
			}
			dp[i] = max(dp[i], dp[0] + a[i][2]);
		}

		/*cout << "info " << p << ' ' << t << ' ' << i << ' ' << e << '\n';
		for (int i = 0; i <= m; ++i)cout << dp[i] << ' ';
		cout << '\n';*/
	}

	cout << dp[0] << '\n';
}

int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("in", "r", stdin);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}